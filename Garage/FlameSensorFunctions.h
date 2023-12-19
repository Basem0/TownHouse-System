#ifndef FLAME_SENSOR_FUNCTIONS_H
#define FLAME_SENSOR_FUNCTIONS_H

int flame_pin = HIGH;
#define flame_sensor_pin A4

void ReadFlameSensor(){
  flame_pin = digitalRead(flame_sensor_pin);
}

#endif  // FLAME_SENSOR_FUNCTIONS_H
