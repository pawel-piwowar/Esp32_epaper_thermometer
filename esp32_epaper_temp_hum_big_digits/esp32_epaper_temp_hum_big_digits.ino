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
EpaperBigDigits epaperBigDigits;

void initTempSensor() {
  if (sensor.init()) {
    printf("sensor init failed!!!");
  }
}

void init() {
  initTempSensor();
  epaperBigDigits.digits_init();
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

  epaperBigDigits.drawFloat(x, y, hum, HUMIDITY);
  DEV_Delay_ms(HUM_SHOW_SECONDS * 1000);

  epaperBigDigits.drawFloat(x, y, temp, TEMPERATURE);
}

/* Entry point ----------------------------------------------------------------*/
void setup() {
  esp_sleep_enable_timer_wakeup(SLEEP_SECONDS * uS_TO_S_FACTOR);
  init();
}

/* The main loop -------------------------------------------------------------*/
void loop() {
  DEV_Delay_ms(1000);
  Paint_Clear(WHITE);
  showTempAndHum();
  DEV_Delay_ms(50);
  esp_light_sleep_start();
}
