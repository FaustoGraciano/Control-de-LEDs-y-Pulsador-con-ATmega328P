# 💡 Control de LEDs y Pulsador con ATmega328P

## 📌 Descripción
Este proyecto implementa el **control de periféricos externos** utilizando los puertos de entrada y salida de un **microcontrolador ATmega328P**.  
El sistema controla **8 LEDs conectados al puerto B**, permitiendo encenderlos mediante distintas **secuencias de iluminación**, las cuales pueden alternarse utilizando un **pulsador**.

Además, se implementa un **algoritmo antirebote por software** para garantizar una detección confiable del pulsador sin bloquear la ejecución del programa.

El proyecto fue desarrollado y simulado en **Proteus**.

---

## ▶️ Cómo ejecutar el programa
1. Abrir el proyecto en **Proteus**.
2. Cargar el archivo `.hex` generado a partir del código en C en el **ATmega328P**.
3. Iniciar la simulación.
4. Los LEDs comenzarán a encenderse automáticamente siguiendo la secuencia inicial.

---

## 🕹️ Cómo usar el sistema
- Al iniciar, se ejecuta la **secuencia 1**:
  - Encendido simultáneo de LEDs desde los extremos hacia el centro  
    (`b0–b7`, `b1–b6`, `b2–b5`, `b3–b4`)
- **Presionar y soltar el pulsador** cambia a la **secuencia 2**:
  - Encendido de LEDs en forma escalonada desde `b7` hasta `b0`
- Cada nueva pulsación alterna entre ambas secuencias.
- Si el pulsador se mantiene presionado, la secuencia continúa sin interrupciones.

---

## ⚙️ Implementación (resumen técnico)
- **Microcontrolador:** ATmega328P
- **Periféricos utilizados:**
  - 8 LEDs de distintos colores
  - Resistencias en serie para limitación de corriente
  - Pulsador con **Pull-Up externo**
- **Lenguaje:** C
- **Características principales:**
  - Configuración de puertos de E/S (PORTB y PORTC)
  - Control de LEDs mediante operaciones a nivel de bits
  - Algoritmo **antirebote por software** sin uso de delays bloqueantes
  - Temporización mediante contadores para permitir respuesta al usuario

---

## 📚 Contexto académico
Trabajo Práctico N.º 1  
**Circuitos Digitales y Microcontroladores – UNLP**

---

## 📄 Licencia
Este proyecto se distribuye bajo la **MIT License**.

