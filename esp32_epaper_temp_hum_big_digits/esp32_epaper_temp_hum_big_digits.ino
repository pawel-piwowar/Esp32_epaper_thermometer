/*Includes ------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include <stdlib.h>
#include "Epaper-digits.h"

#include "Seeed_SHT35.h"

#define SLEEP_SECONDS 10
#define HUM_SHOW_SECONDS 2

#define uS_TO_S_FACTOR 1000000 /* Conversion factor for micro seconds to seconds */

/*SAMD core*/
#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
#define SDAPIN 20
#define SCLPIN 21
#define RSTPIN 7
#define SERIAL SerialUSB
#else
#define SDAPIN A4
#define SCLPIN A5
#define RSTPIN 2
#define SERIAL Serial
#endif

SHT35 sensor(SCLPIN);

RTC_DATA_ATTR float temp, hum;

UBYTE *Image;

EpaperBigDigits epaperBigDigits;

enum Display_type {
  TEMPERATURE,
  HUMIDITY
};

void initTempSensor() {
  if (sensor.init()) {
    printf("sensor init failed!!!");
  }
}

void initEpaper() {
  printf("epaper init starting...\r\n");
  DEV_Module_Init();
  EPD_2in13_V4_Init();

  //Create a new image cache
  UWORD Imagesize = ((EPD_2in13_V4_WIDTH % 8 == 0) ? (EPD_2in13_V4_WIDTH / 8) : (EPD_2in13_V4_WIDTH / 8 + 1)) * EPD_2in13_V4_HEIGHT;
  if ((Image = (UBYTE *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    while (1)
      ;
  }
  Paint_NewImage(Image, EPD_2in13_V4_WIDTH, EPD_2in13_V4_HEIGHT, 90, WHITE);
  Paint_Clear(WHITE);
  DEV_Delay_ms(2000);
}

void drawDigit(int digit, int *x, int y, int font_high, int font_width) {
  Paint_DrawImage(gImage_digits[digit], y, *x, font_high, font_width);
  *x = *x + font_width;
  return;
}

void drawSymbol(int *x, int y, int font_high, int font_width, const unsigned char gImage[]) {
  Paint_DrawImage(gImage, y, *x, font_high, font_width);
  *x = *x + font_width;
  return;
}

void drawDigits(int x, int y, int digits[], Display_type display_type) {
  for (int i = 0; i <= 1; i++) {
    drawDigit(digits[i], &x, y, digits_font_high, digits_font_width);
  }
  drawSymbol(&x, y, digits_font_high, digits_dot_width, gImage_dot);
  for (int i = 2; i <= 3; i++) {
    drawDigit(digits[i], &x, y, digits_font_high, digits_font_width);
  }
  if (display_type == TEMPERATURE) {
    drawSymbol(&x, y, digits_font_high, digits_celc_width, gImage_celc);
  } else {
    drawSymbol(&x, y, digits_font_high, digits_perc_width, gImage_perc);
  }
  EPD_2in13_V4_Display_Partial(Image);
}

void calc_digits(int digits[4], int *position, int *rest) {
  int multiplier = pow(10, 3 - *position);
  int digit_value = (int)(*rest / multiplier);
  digits[*position] = digit_value;
  *rest = *rest - digit_value * multiplier;
  *position = *position + 1;
  return;
}

void drawFloat(int x, int y, float value, Display_type display_type) {
  int digits[4];
  int position = 0;
  int rest = int(value * 100);
  for (int i = 0; i < 4; i++) {
    calc_digits(digits, &position, &rest);
  }
  drawDigits(x, y, digits, display_type);
}

void showTempAndHum() {
  int x = 0;
  int y = 20;
  printf("show temp and hum \r\n");

  sensor.read_meas_data_single_shot(HIGH_REP_WITH_STRCH, &temp, &hum);

  SERIAL.print("Temp : ");
  SERIAL.println(temp);

  SERIAL.print("Hum : ");
  SERIAL.println(hum);

  drawFloat(x, y, hum, HUMIDITY);
  DEV_Delay_ms(HUM_SHOW_SECONDS * 1000);

  drawFloat(x, y, temp, TEMPERATURE);

  EPD_2in13_V4_Display_Partial(Image);
}

void init() {
  initTempSensor();
  initEpaper();
  epaperBigDigits.digits_init();
  EPD_2in13_V4_Display_Base(Image);
}

/* Entry point ----------------------------------------------------------------*/
void setup() {
  esp_sleep_enable_timer_wakeup(SLEEP_SECONDS * uS_TO_S_FACTOR);
  init();
}

/* The main loop -------------------------------------------------------------*/
void loop() {
  DEV_Delay_ms(1000);
  showTempAndHum();
  DEV_Delay_ms(50);
  esp_light_sleep_start();
}
