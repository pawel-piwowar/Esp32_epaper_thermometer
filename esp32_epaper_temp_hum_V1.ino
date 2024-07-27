/* Includes ------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>

#include "Seeed_SHT35.h"

#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  10        /* Time ESP32 will go to sleep (in seconds) */


/*SAMD core*/
#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
  #define SDAPIN  20
  #define SCLPIN  21
  #define RSTPIN  7
  #define SERIAL SerialUSB
#else
  #define SDAPIN  A4
  #define SCLPIN  A5
  #define RSTPIN  2
  #define SERIAL Serial
#endif

SHT35 sensor(SCLPIN);
RTC_DATA_ATTR int bootCount = 0;
RTC_DATA_ATTR float temp,hum;
UBYTE *BlackImage;

void initTempSensor(){

    if(sensor.init())
    {
      printf("sensor init failed!!!");
    }

}

void initEpaper(){
  SERIAL.println("------------- epaper init starting");
	DEV_Module_Init();

	printf("e-Paper Init and Clear...\r\n");
	EPD_2in13_V4_Init();

	//Create a new image cache
	UWORD Imagesize = ((EPD_2in13_V4_WIDTH % 8 == 0)? (EPD_2in13_V4_WIDTH / 8 ): (EPD_2in13_V4_WIDTH / 8 + 1)) * EPD_2in13_V4_HEIGHT;
	if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) 
	{
		printf("Failed to apply for black memory...\r\n");
		while (1);
	}
	printf("Paint_NewImage\r\n");
	Paint_NewImage(BlackImage, EPD_2in13_V4_WIDTH, EPD_2in13_V4_HEIGHT, 90, WHITE);
	Paint_Clear(WHITE);

	Paint_DrawString_EN(20, 30, "Temp", &Font24, WHITE, BLACK);
  Paint_DrawString_EN(140, 30, "Hum", &Font24, WHITE, BLACK);
	
  Paint_DrawString_EN(5, 60, "*", &Font24, WHITE, BLACK);
  Paint_DrawString_EN(125, 60, "*", &Font24, WHITE, BLACK);

	EPD_2in13_V4_Display_Base(BlackImage);

}

void init(){
  initTempSensor();
  initEpaper();
}

void printFloat(int x, int y, float value, char* format){
    char buffer[16];
    int ret = snprintf(buffer, sizeof buffer, format, value);
    Paint_ClearWindows(x, y, x + (strlen(buffer) * 20), y+24, WHITE);
   	Paint_DrawString_EN(x, y, buffer, &Font24, WHITE, BLACK);
}

void printInt(int x, int y, int value){
    char buffer[16];
    int ret = snprintf(buffer, sizeof buffer, "%i", value);
    Paint_ClearWindows(x, y, x + (strlen(buffer) * 20), y+24, WHITE);
   	Paint_DrawString_EN(x, y, buffer, &Font20, WHITE, BLACK);
}

void showTempAndHum(){
    printf("show temp and hum \r\n");
    printInt(180,10,bootCount);

    Paint_DrawString_EN(5, 60, "*", &Font24, WHITE, BLACK);
    printFloat(20,90,temp, "%.2f");
    printFloat(140,90,hum, "%.2f");

    u16 value=0;
    u8 data[6]={0};
    sensor.read_meas_data_single_shot(HIGH_REP_WITH_STRCH,&temp,&hum);

    printFloat(20,60,temp, "%.2f");
    printFloat(140,60,hum, "%.2f");

 	  EPD_2in13_V4_Display_Partial(BlackImage);
}

/* Entry point ----------------------------------------------------------------*/
void setup()
{
   esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
   init();
}

/* The main loop -------------------------------------------------------------*/
void loop()
{
  showTempAndHum();
  DEV_Delay_ms(50);
  bootCount++; 
  esp_light_sleep_start();
}

