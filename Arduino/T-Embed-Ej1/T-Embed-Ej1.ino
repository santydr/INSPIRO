/*************************************************************************************************************
 *                                                                                                           *
 * Título: Ejemplo_1 - Hola mundo!                                                                           *
 * Autor: Santiago Díaz Romero.                                                                              *
 * Objetivo: Introducción y primera aproximación al IDE Arduino y el dispositivo T-Embed.                    *
 *                                                                                                           * 
 *************************************************************************************************************/
 
 /*************************************************************************************************************
  * Setup contiene todos los pasos que sean necesarios realizar una sola vez antes de empezar el programa.    *
  * Se llama setup porque suele contener la configuración necesaria para iniciar el resto del programa.       *
  *************************************************************************************************************/
void setup() { 
  Serial.begin(115200);         // Se abre el puerto serie para poder enviar información.
  delay(5000);                  // (Opcional) Se esperan 5 segundos para que de tiempo a abrir el monitor serie.
  Serial.printf("HOLA MUNDO!")  // Se imprime el mensaje por puerto serie.
}

 /*************************************************************************************************************
  * Loop contiene la secuencia de instrucciones del programa en sí. Es un bucle infinito.                     *
  * Se llama setup porque suele contener la configuración necesaria para iniciar el resto del programa.       *
  *************************************************************************************************************/
void loop() {
  delay(1000);                // Solo espera 1s de forma reiterada, infinitamente.
}
