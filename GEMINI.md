# Reglas del Proyecto Arduino

- **Objetivo:** Crear un seguidor de línea para Arduino Nano/Uno, sensor HY-S301 y driver L298N.
- **Estructura:** Usar programación orientada a objetos con clases y funciones en archivos separados (`.h` y `.cpp`).
- **Constantes:** Usar `#define` para todos los pines y constantes de velocidad.
- **Tipos de Datos:** Preferir `uint8_t` o `uint16_t`, segun corresponda sobre `int` siempre que sea posible para ahorrar memoria.
- **Strings:** Usar la macro `F()` para todos los strings literales en `Serial.print()` y `Serial.println()` para conservar RAM.
- **Optimización:** Priorizar la optimización del uso de memoria RAM y Flash, dado que el ATmega328P tiene recursos muy limitados.
