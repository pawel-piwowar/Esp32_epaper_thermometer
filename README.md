# Esp32_epaper_thermometer

## Hardware used:
- 2.13inch E-Paper Cloud Module, 250×122, WiFi Connectivity : https://www.waveshare.com/2.13inch-e-paper-cloud-module.htm
- Grove - I2C High Accuracy Temp&Humi Sensor(SHT35) : https://wiki.seeedstudio.com/Grove-I2C_High_Accuracy_Temp%26Humi_Sensor-SHT35/

![hardware.png](images/hardware.png)

## Wiring
Since E-Paper Cloud Module contains integrated ESP32, wiring is  pretty easy.  
![wiring.png](images/wiring.png)

Please note, that in case of this board, you will have to solder wires to ESP32 chip, since this board does not have gold pins, or even an option to mount them.  

![wiring2.png](images/wiring2.png)


## Required libraries sources:
- 2.13inch e-Paper Cloud Module : https://www.waveshare.com/wiki/2.13inch_e-Paper_Cloud_Module
- Temperature sensor STH35: https://github.com/Seeed-Studio/Seeed_SHT35

## Project features
- High precision temperature sensor SHT35 is used with precision 0.1 - 0.2 °C
- 2.13inch E-Paper Cloud Module has ESP32 chip and attached battery. The final package is light and small. 
Could be used without external power source. Also could be powered and charged via usb-c without any additional circuits  
- Very low power consumption, light sleep mode of ESP32 is used. 
- Partial screen refresh function is used. Screen does not flicker, like it does when full refresh is made. 
Other sleep modes (e.g. deep sleep) could be used as well reducing power consumption even more (however I did not manage to avoid screen refreshes after deep sleep wake up).
- Display layout can be easily changed. In this example two readings are shown: current reading (marked with asterisk symbol) and previous one shown in a row below.
- Temperature and humidity readings are made every 10 seconds, it could be changed to any other value according to our needs
- ESP32 features WIFI connection capabilities. This could be added to a project using ESP32 libraries.

## Final effect

![hardware-final.png](images/hardware-final.png)