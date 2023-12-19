#ifndef LCD_FUNCTIONS_H
#define LCD_FUNCTIONS_H
#include <Arduino.h>

void LCDInitialization();
void LCDDisplay(int Humidity, int temperature, int gas, int newGyro, int oldGyro);

#endif
