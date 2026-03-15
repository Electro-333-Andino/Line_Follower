#ifndef Sensor_h
#define Sensor_h

#include <Arduino.h>

// ========== PINES SENSOR HY-S301 ==========
#define SENSOR_D1 A0
#define SENSOR_D2 A1
#define SENSOR_D3 A2
#define SENSOR_D4 A3
#define SENSOR_D5 A4
#define SENSOR_D6 A5
#define SENSOR_D7 11
#define SENSOR_D8 12

// ========== TIEMPO CALIBRACION ==========
#define T_CALIBRACION 10000

// ========== PINES LEDS ==========
#define LED_ROJO 2
#define LED_VERDE 3

class Sensor {
public:
  Sensor();
  void leer(uint8_t valores[8]);
  void calibrar();

private:
  uint8_t _pins[8];
};

#endif
