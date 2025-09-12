/*************************************************************************************************************
 *                                                                                                           *
 * Título: Ejemplo_5 - Pantalla.                                                                             *
 * Autor: Santiago Díaz Romero.                                                                              *
 * Objetivo: Aprender el uso básico de la pantalla integrada en el dispositivo y uso básico de la libreria   *
 *           asociada.                                                                                       *
 *                                                                                                           * 
 *************************************************************************************************************/

// Se importa la librería RotaryEncoder que permite controlar el encoder de forma sencilla.
#include <TFT_eSPI.h>

// Se definen los pines asociado a la pantalla.
#define PIN_LCD_BL            15
#define PIN_LCD_DC            13
#define PIN_LCD_CS            10
#define PIN_LCD_CLK           12
#define PIN_LCD_MOSI          11
#define PIN_LCD_RES           9

//Se define el pin de encendido de la pantalla. (Obtenidos de la web del fabricante).
#define PIN_POWER_ON          46

TFT_eSPI tft = TFT_eSPI(170, 320);                // Se crea una variable tft que es un objeto de tipo TFT_eSPI de tamaño 170 x 320 pixeles.

void setup() {
  delay(2000);
  pinMode(PIN_POWER_ON, OUTPUT);                  // Configura el pin de encendido como salida.
  digitalWrite(PIN_POWER_ON, HIGH);               // Enciende la pantalla.
  tft.begin();                                    // Se inicia la pantalla.
  tft.setRotation(3);                             // Se establece la rotación de la pantalla. Depende de cómo se oriente el dispositivo.
  tft.setTextFont(2);                             // Se establece el tipo de la letra en 2.
  
}

void loop() {
  tft.setTextColor(TFT_WHITE,TFT_BLACK);          // Se establece el color de la letra en blanco con fondo negro.
  tft.fillScreen(TFT_BLACK);                      // Se pone la pantalla completamente negra.
  tft.setCursor(130, 75);                         // Se establece el cursor en la posición x=130, y=75.
  tft.print("Hola mundo!");                       // Se escribe "Hola mundo!" en la pantalla.
  delay(10000);                                   // Se esperan 10 segundos.
  //tft.invertDisplay(false);                     // Se invierten los colores de la pantalla.
  //delay(10000);                                 // Se esperan 10 segundos.
  //tft.invertDisplay(true);                      // Se dejan de invertir los colores.
  tft.fillScreen(TFT_BLACK);                      // Se pone la pantalla completamente negra (para borrarla).
  tft.drawRect(320/2-56/2, 170/2-56/2, 56, 56, TFT_RED);    // Dibuja un cuadrado hueco rojo de 56x56 en el centro de la pantalla.
  tft.fillRect(320/2-50/2, 170/2-50/2, 50, 50, TFT_GREEN);  // Dibuja un cuadrado sólido verde de 50x50 en el centro de la pantalla.
  tft.drawCircle(320/4, 170/2, 28, TFT_YELLOW);             // Dibuja un circulo hueco amarillo de 28 pixeles de radio en el 1er tercio de la pantalla.
  tft.fillCircle(320/4, 170/2, 25, TFT_BLUE);               // Dibuja un circulo sólido azul de 25 pixeles de radio en el 1er tercio de la pantalla.
  tft.drawTriangle((3*320)/4-28, (170/2)-28, (3*320)/4+28, (170/2)-28, (3*320)/4, (170/2)+28, TFT_ORANGE);  // Dibuja un triángulo hueco naranja de 56 pixeles en el 3er tercio de la pantalla.
  tft.fillTriangle((3*320)/4-25, (170/2)-25, (3*320)/4+25, (170/2)-25, (3*320)/4, (170/2)+25, TFT_PINK);    // Dibuja un triángulo sólido rosa de 50 pixeles de radio en el 3er tercio de la pantalla.
  delay(10000);                                   // Espera 10 segundos antes de repetir el ciclo.
}
