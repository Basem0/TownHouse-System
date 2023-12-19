#include "LCDFunctions.h"
#include <LiquidCrystal.h>

LiquidCrystal My_LCD(13, 12, 14, 27, 26, 25);

void LCDInitialization() {
    My_LCD.begin(16, 2);
    My_LCD.print("Hello Beso!");
    My_LCD.clear();
    delay(2000);
    My_LCD.clear();
}

void LCDDisplay(int Humidity, int temperature, int gas, int newGyro, int oldGyro) {
    My_LCD.setCursor(0, 0);
    My_LCD.print("HUM:");
    My_LCD.print(Humidity);
    My_LCD.print(" - TEMP:");
    My_LCD.print(temperature);

    My_LCD.setCursor(0, 1);
    My_LCD.print("Gas:");
    My_LCD.print(gas);

    if (abs(newGyro - oldGyro) >= 5) {
        My_LCD.clear();
        My_LCD.setCursor(0, 0);
        My_LCD.print("There Is An EarthQuake");

        My_LCD.setCursor(0, 1);
        My_LCD.print("Please Take Care");
    } else {
        if ((temperature > 50) || (gas > 60) || (Humidity > 70)) {
            My_LCD.setCursor(8, 1);
            My_LCD.print("UNSTABLE");
        } else {
            My_LCD.setCursor(8, 1);
            My_LCD.print("  STABLE");
        }
    }
}
