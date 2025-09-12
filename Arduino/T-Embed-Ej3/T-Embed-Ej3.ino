/*************************************************************************************************************
 *                                                                                                           *
 * Título: Ejemplo_3 - BOTON.                                                                                *
 * Autor: Santiago Díaz Romero.                                                                              *
 * Objetivo: Aprender el uso básico del botón integrado en el dispositivo y uso básico de la libreria        *
 *           asociada.                                                                                       *
 *                                                                                                           * 
 *************************************************************************************************************/

// Se importa la librería One Button que permite controlar el boton de forma sencilla.
#include <OneButton.h>

// Se define el pin asociado al botón.
#define PIN_ENCODE_BTN        0

OneButton button(PIN_ENCODE_BTN, true);   // Se crea una variable button que es un objeto de tipo OneButton.

void setup() {
  Serial.begin(115200);                   // Se abre el puerto serie para depurar el código.
  Serial.printf("Iniciado puerto serie.\n");
  button.attachClick(unClick);            // Cuando se produzca un click llamará a la función unClick.
  button.attachDoubleClick(dosClick);     // Cuando se produzca un doble click llamará a la función dosClick.
  button.attachLongPressStop(clickLargo); // Cuando se suelte despues de un click largo llamará a la función clickLargo.
}

void loop() {
  button.tick();  // Comprueba el estado del botón.
  delay(10);
}

void unClick(){
  Serial.printf("Click.\n");
}

void dosClick(){
  Serial.printf("Doble click.\n");
}

void clickLargo(){
  // Indica durante cuanto tiempo se ha tenido pulsado el botón antes de soltarlo.
  Serial.printf("Click largo de %3.2f segundos.\n", button.getPressedMs()/1000.0);  
}
