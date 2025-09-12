/*************************************************************************************************************
 *                                                                                                           *
 * Título: Ejemplo_2 - LEDs.                                                                                 *
 * Autor: Santiago Díaz Romero.                                                                              *
 * Objetivo: Aprender el uso de los LEDs direccionables APA102 integrados en el dispositivo y uso básico de  *
 *           la libreria asociada.                                                                           *
 *                                                                                                           * 
 *************************************************************************************************************/

// Se importa la librería APA102 que permite controlar los LEDs de forma sencilla.
#include <APA102.h>

// Se definen los pines asociados al reloj y los datos de los LEDS. (Obtenidos de la web del fabricante).
#define PIN_APA102_CLK        45
#define PIN_APA102_DI         42

//Se define el pin de encendido de los LEDs. (Obtenidos de la web del fabricante).
#define PIN_POWER_ON          46

APA102<PIN_APA102_DI, PIN_APA102_CLK> ledStrip; // Se crea una variable ledStrip que es un objeto de tipo APA102.

const uint16_t ledCount = 7;  // Se define la cantidad de LEDS (7 en este caso).
rgb_color colors[ledCount];   // Crea un vector de colores. Un color para cada LED (pueden ser diferentes).
uint8_t brightness = 5;       // Se define el brillo deseado: mínimo 1 y máximo 31.


void setup() {
  pinMode(PIN_POWER_ON, OUTPUT);                  // Configura el pin de encendido como salida.
  digitalWrite(PIN_POWER_ON, HIGH);               // Enciende los LEDs.
}

void loop() {
  for (uint16_t i = 0; i < ledCount; i++) {       // Recorre todos los LEDs.
    colors[i] = rgb_color(0, 255, 0);             // Ajusta el color deseado de cada LED.
  }
  ledStrip.write(colors, ledCount, brightness);   // Envía el color al LED. ¡Hasta que no se hace esto el color no cambia!
  delay(100);                                     // Espera 0.1 segundos antes de volver a realizar el proceso.
}
