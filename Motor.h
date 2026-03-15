#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

// ========== PINES L298N ==========
#define ENA 9
#define IN1 7
#define IN2 6
#define ENB 10
#define IN3 5
#define IN4 4

class Motor {
public:
  Motor();
  void avanzar(uint8_t velocidadIzquierda, uint8_t velocidadDerecha);
  void detener();

private:
  // No hay miembros privados necesarios por ahora
};

#endif
