 /*Includes ------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include <stdlib.h>

#include "Seeed_SHT35.h"

#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */

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
RTC_DATA_ATTR int tempChartCounter = 0;
RTC_DATA_ATTR int humChartCounter = 0;
RTC_DATA_ATTR float temp,hum;
RTC_DATA_ATTR int tempChartMiddleValue = -100;
RTC_DATA_ATTR int humChartMiddleValue = -100;
UBYTE *Image;

void initTempSensor(){
  if(sensor.init())
  {
    printf("sensor init failed!!!");
  }
}

void initEpaper(){
  printf("epaper init starting...\r\n");
  DEV_Module_Init();
  EPD_2in13_V4_Init();

  //Create a new image cache
  UWORD Imagesize = ((EPD_2in13_V4_WIDTH % 8 == 0)? (EPD_2in13_V4_WIDTH / 8 ): (EPD_2in13_V4_WIDTH / 8 + 1)) * EPD_2in13_V4_HEIGHT;
  if((Image = (UBYTE *)malloc(Imagesize)) == NULL)
  {
    printf("Failed to apply for black memory...\r\n");
    while (1);
  }
  printf("Paint_NewImage\r\n");
  Paint_NewImage(Image, EPD_2in13_V4_WIDTH, EPD_2in13_V4_HEIGHT, 90, WHITE);
  Paint_Clear(WHITE);
}

void drawTemplate(){

  Paint_DrawLine(15, 40, 225, 40, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  Paint_DrawLine(115, 10, 115, 120, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);

  EPD_2in13_V4_Display_Base(Image);
}

void init(){
  initTempSensor();
  initEpaper();
  drawTemplate();
}

void printInt(int x, int y, int value){
  char buffer[16];
  int ret = snprintf(buffer, sizeof buffer, "%i", value);
  Paint_DrawString_EN(x, y, buffer, &Font12, WHITE, BLACK);
}

void drawChart(int x, int y, float current, float previous, int middle, int unitStep, int counter){
 float chartPixelsPerUnit = 25 / unitStep;
 float offsetCurrent = current - (float)middle;
 int offsetCurrentY = (int)(offsetCurrent * chartPixelsPerUnit + 25);

 float offsetPrevious = previous - (float)middle;
 int offsetPreviousY = (int)(offsetPrevious * chartPixelsPerUnit + 25);

 if (counter == 0) {
  offsetPreviousY = offsetCurrentY;
 }

 Paint_DrawLine(x, y-offsetPreviousY, x, y-offsetCurrentY, BLACK, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
}

void resetChart(int x, int y, float value, int middleValue, int unitStep){
  int middleY = y-25;
  int lowY = y;
  int highY = y-50;
  Paint_ClearWindows(x, y-60, x + 100, y + 5, WHITE);
  int lineXStart = x+20;
  int lineXEnd = x+100;
  Paint_DrawLine(lineXStart, middleY, lineXEnd, middleY, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  Paint_DrawLine(lineXStart,lowY, lineXEnd, lowY, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  Paint_DrawLine(lineXStart, highY, lineXEnd, highY, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  printInt(x, middleY-5, middleValue);
  printInt(x, lowY-5, middleValue - unitStep);
  printInt(x, highY-5, middleValue + unitStep);
}

boolean shoudResetChart(float value, int middleValue, int counter, int unitOffset){
    bool valueOutsideChart = value > (middleValue + unitOffset) || value < middleValue - unitOffset;
    bool counterMaxReached = counter > 80;
    return valueOutsideChart || counterMaxReached;
}

void printFloat(int x, int y, float value, char* format, char* unitSymbol){
  char buffer[16];
  int ret = snprintf(buffer, sizeof buffer, format, value);
  if (ret < 0) {
    throw;
  }
  Paint_ClearWindows(x, y, x + (strlen(buffer) * 18), y+24, WHITE);
  Paint_DrawString_EN(x, y, strcat(buffer, unitSymbol), &Font24, WHITE, BLACK);
}

void showTempAndHum(){
  printf("show temp and hum \r\n");
  float previousTempValue = temp;
  float previousHumValue = hum;
  sensor.read_meas_data_single_shot(HIGH_REP_WITH_STRCH,&temp,&hum);

  // display current readings
  printFloat(1,10,temp, "%.2f", "C");
  printFloat(145,10,hum, "%.1f", "%");

  int tempChartYEnd = 115;
  int tempChartXStart = 1;
  int tempChartUnitOffset = 2;

  int humChartYEnd = 115;
  int humChartXStart = 120;
  int humChartUnitOffset = 10;

  if (shoudResetChart(temp, tempChartMiddleValue, tempChartCounter, tempChartUnitOffset )){
    tempChartMiddleValue = std::round(std::round(temp / tempChartUnitOffset) * tempChartUnitOffset);
    resetChart(tempChartXStart, tempChartYEnd, temp, tempChartMiddleValue, tempChartUnitOffset) ;
    tempChartCounter = 0;
  }

  if (shoudResetChart(hum, humChartMiddleValue, humChartCounter, humChartUnitOffset)){
    humChartMiddleValue = std::round(std::round(hum / humChartUnitOffset) * humChartUnitOffset);
    resetChart(humChartXStart, humChartYEnd, hum, humChartMiddleValue, humChartUnitOffset);
    humChartCounter = 0;
  }

  drawChart(tempChartXStart + 20 + tempChartCounter, tempChartYEnd, temp, previousTempValue, tempChartMiddleValue, tempChartUnitOffset, tempChartCounter);
  drawChart(humChartXStart + 20 + humChartCounter, humChartYEnd, hum, previousHumValue, humChartMiddleValue, humChartUnitOffset, humChartCounter);

  tempChartCounter++;
  humChartCounter++;

  EPD_2in13_V4_Display_Partial(Image);
}

/* Entry point ----------------------------------------------------------------*/
void setup()
{
  int sleepSeconds = 1;
  esp_sleep_enable_timer_wakeup(sleepSeconds * uS_TO_S_FACTOR);
  init();
}

/* The main loop -------------------------------------------------------------*/
void loop()
{
  showTempAndHum();
  DEV_Delay_ms(50);
  esp_light_sleep_start();
}

