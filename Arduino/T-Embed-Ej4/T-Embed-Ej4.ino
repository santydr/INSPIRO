/*************************************************************************************************************
 *                                                                                                           *
 * Título: Ejemplo_4 - Encoder.                                                                              *
 * Autor: Santiago Díaz Romero.                                                                              *
 * Objetivo: Aprender el uso básico del encoder rotatorio integrado en el dispositivo y uso básico de la     *
 *           libreria asociada.                                                                              *
 *                                                                                                           * 
 *************************************************************************************************************/

// Se importa la librería RotaryEncoder que permite controlar el encoder de forma sencilla.
#include <RotaryEncoder.h>

// Se definen los pines asociados al encoder.
#define PIN_ENCODE_A          2
#define PIN_ENCODE_B          1

// Se crea una variable encoder que es un objeto de tipo RotaryEncoder.
RotaryEncoder encoder(PIN_ENCODE_A, PIN_ENCODE_B, RotaryEncoder::LatchMode::TWO03);

int pos = 0;

void setup() {
  Serial.begin(115200);                   // Se abre el puerto serie para depurar el código.
  Serial.printf("Iniciado puerto serie.\n");
}

void loop() {
  encoder.tick();     // Comprueba el estado del encoder.

  int newPos = encoder.getPosition();           // Guarda la nueva posición.
  int direction= (int)(encoder.getDirection()); // Guarda la dirección de la rotación.

  if (pos != newPos) {                          // Comprueba que la posición ha cambiado desde la última vez.
    Serial.print("pos:");                       
    Serial.print(newPos);
    Serial.print(" dir:");
    Serial.println(direction);
    pos = newPos;                               // La posición obtenida pasa a ser antigua antes de volver a leer.
  }

  // Si no es necesario conocer la posición sino saber si se ha girado el encoder puede hacerse de este modo.
  if (direction == -1){                         // Si la dirección es -1, es que ha girado a la derecha.
    Serial.println("Giro a la derecha.");
  }
  else if (direction == 1){
    Serial.println("Giro a la izquierda.");     // Si la dirección es 1, es que ha girado a la izquierda.
  }                      
}
