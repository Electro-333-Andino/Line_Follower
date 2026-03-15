# Seguidor de línea para Arduino

Este proyecto implementa un robot seguidor de línea para Arduino, diseñado con los siguientes componentes y funcionalidades clave:

-   **Sensor de línea:** Utiliza el sensor HY-S301 para la detección de la línea.
-   **Driver de motores:** Incorpora el driver L298N para controlar los motores del robot.
-   **Indicadores LED:**
    *   Un LED parpadea para indicar que el sensor HY-S301 necesita ser calibrado.
    *   Otro LED se activa de forma continua para señalar que el robot está listo para iniciar su recorrido.
-   **Tiempos de espera:** El sistema incluye tiempos de espera específicos para la interacción con los LEDs y el inicio de las operaciones:
    *   **Calibración:** El proceso de calibración del sensor dura 10 segundos.
    *   **Inicio:** Tras la calibración, el robot esperará 4 segundos antes de comenzar su recorrido.
