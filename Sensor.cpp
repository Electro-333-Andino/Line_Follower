#include "Sensor.h"

Sensor::Sensor() {
  _pins[0] = SENSOR_D1;
  _pins[1] = SENSOR_D2;
  _pins[2] = SENSOR_D3;
  _pins[3] = SENSOR_D4;
  _pins[4] = SENSOR_D5;
  _pins[5] = SENSOR_D6;
  _pins[6] = SENSOR_D7;
  _pins[7] = SENSOR_D8;

  for (uint8_t i = 0; i < 8; i++) {
    pinMode(_pins[i], INPUT);
  }
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}

void Sensor::leer(uint8_t valores[8]) {
  for (uint8_t i = 0; i < 8; i++) {
    valores[i] = digitalRead(_pins[i]);
  }
}

void Sensor::calibrar() {
  Serial.println(F("
=== CALIBRACION ==="));
  Serial.print(F("Tiempo: "));
  Serial.print(T_CALIBRACION / 1000);
  Serial.println(F(" seg"));
  Serial.println(F("1=NEGRO 0=BLANCO
"));

  uint16_t detBlanco[8] = {0};
  uint16_t detNegro[8] = {0};
  uint32_t inicio = millis();
  uint32_t reporte = millis();

  while (millis() - inicio < T_CALIBRACION) {
    if (millis() % 200 < 100) {
      digitalWrite(LED_ROJO, HIGH);
    } else {
      digitalWrite(LED_ROJO, LOW);
    }

    if (millis() - reporte >= 1000) {
      Serial.print(F("T:"));
      Serial.println((T_CALIBRACION - (millis() - inicio)) / 1000);
      reporte = millis();
    }

    uint8_t s[8];
    leer(s);

    for (uint8_t i = 0; i < 8; i++) {
      if (s[i]) {
        detNegro[i]++;
      } else {
        detBlanco[i]++;
      }
    }

    delay(10);
  }

  digitalWrite(LED_ROJO, LOW);

  Serial.println(F("
=== RESULTADOS ==="));
  Serial.println(F("S  B    N   Estado"));

  uint8_t ok = 0;

  for (uint8_t i = 0; i < 8; i++) {
    Serial.print(F("D"));
    Serial.print(i + 1);
    Serial.print(' ');
    Serial.print(detBlanco[i]);
    Serial.print(' ');
    Serial.print(detNegro[i]);
    Serial.print(' ');

    if (detBlanco[i] > 0 && detNegro[i] > 0) {
      Serial.println(F("OK"));
      ok++;
    } else if (detBlanco[i] == 0 && detNegro[i] == 0) {
      Serial.println(F("ERR"));
    } else {
      Serial.println(F("WARN"));
    }
  }

  Serial.print(F("
OK: "));
  Serial.print(ok);
  Serial.println(F("/8"));

  if (ok < 3) {
    Serial.println(F("Pocos sensores!"));
  } else if (ok >= 6) {
    Serial.println(F("Sistema listo!"));
  }
  
  digitalWrite(LED_VERDE, HIGH);
}
