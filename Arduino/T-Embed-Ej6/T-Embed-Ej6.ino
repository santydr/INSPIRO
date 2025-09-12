/*************************************************************************************************************
 *                                                                                                           *
 * Título: Ejemplo_6 - Juntando cosas.                                                                       *
 * Autor: Santiago Díaz Romero.                                                                              *
 * Objetivo: Integrar lo aprendido en los ejemplos anteriores.                                               *
 *                                                                                                           * 
 *************************************************************************************************************/

// Se importa la librería APA102 que permite controlar los LEDs de forma sencilla.
#include <APA102.h>

// Se importa la librería One Button que permite controlar el boton de forma sencilla.
#include <OneButton.h>

// Se importa la librería RotaryEncoder que permite controlar el encoder de forma sencilla.
#include <TFT_eSPI.h>

// Se importa la librería RotaryEncoder que permite controlar el encoder de forma sencilla.
#include <RotaryEncoder.h>

// Se definen los pines asociados al reloj y los datos de los LEDS. (Obtenidos de la web del fabricante).
#define PIN_APA102_CLK        45
#define PIN_APA102_DI         42

// Se define el pin asociado al botón.
#define PIN_ENCODE_BTN        0

// Se definen los pines asociados al encoder.
#define PIN_ENCODE_A          2
#define PIN_ENCODE_B          1

// Se definen los pines asociados a la pantalla.
#define PIN_LCD_BL            15
#define PIN_LCD_DC            13
#define PIN_LCD_CS            10
#define PIN_LCD_CLK           12
#define PIN_LCD_MOSI          11
#define PIN_LCD_RES           9

//Se define el pin de encendido de la pantalla. (Obtenidos de la web del fabricante).
#define PIN_POWER_ON          46

APA102<PIN_APA102_DI, PIN_APA102_CLK> ledStrip;   // Se crea una variable ledStrip que es un objeto de tipo APA102.

const uint16_t ledCount = 7;                      // Se define la cantidad de LEDS (7 en este caso).
rgb_color colors[ledCount];                       // Crea un vector de colores. Un color para cada LED (pueden ser diferentes).
uint8_t brightness = 5;                           // Se define el brillo deseado: mínimo 1 y máximo 31.

OneButton button(PIN_ENCODE_BTN, true);           // Se crea una variable button que es un objeto de tipo OneButton.

// Se crea una variable encoder que es un objeto de tipo RotaryEncoder.
RotaryEncoder encoder(PIN_ENCODE_A, PIN_ENCODE_B, RotaryEncoder::LatchMode::TWO03);

TFT_eSPI tft = TFT_eSPI(170, 320);                // Se crea una variable tft que es un objeto de tipo TFT_eSPI de tamaño 170 x 320 pixeles.

uint8_t colorRGB[] = {0, 0, 0};                   // Vector que almacena los valores RGB.
bool modifica = false;                            // Indica si se está moviendo entre las opciones (false) o modificando valores (true);
int8_t colorSel = 0;                              // Indica el color que se desea modificar.

void setup() {
  pinMode(PIN_POWER_ON, OUTPUT);                  // Configura el pin de encendido como salida.
  digitalWrite(PIN_POWER_ON, HIGH);               // Enciende la pantalla y los LEDs.
  button.attachClick(unClick);                    // Cuando se produzca un click llamará a la función unClick.
  tft.begin();                                    // Se inicia la pantalla.
  tft.setRotation(3);                             // Se establece la rotación de la pantalla. Depende de cómo se oriente el dispositivo.
  tft.setTextFont(4);                             // Se establece la fuente en 2 (Alfabeto limitado, tamaño medio 26px).
  tft.setTextSize(2);                             // Se establece el tamaño de la letra en 2x (52px).
  actualizaPantalla();                            // Escribe en la pantalla.
}

void loop() {
  encoder.tick();                                 // Comprueba el estado del encoder.
  button.tick();                                  // Comprueba el estado del botón.
  int direccion = (int)(encoder.getDirection());  // Guarda la dirección de la rotación.
  if (direccion == -1){                           // Si la dirección es -1, es que ha girado a la derecha.
    if (!modifica){                               // Si NO se está modificando un valor se aumenta el índice de selección.
      colorSel++;
      if (colorSel > 2)                           // Si al aumentar ha desbordado se resetea a 0.
        colorSel = 0;
    }
    else{                                         // Se está modificando un valor.
      if (colorRGB[colorSel] < 255)               // Si no se ha llegado al límite se incrementa ese valor.
        colorRGB[colorSel]++;
    }
    actualizaPantalla();
  }
  else if (direccion == 1){                       // Si la dirección es 1, es que ha girado a la izquierda.
    if (!modifica){                               // Si NO se está modificando un valor se reduce el indice de selección.
      colorSel--;
      if (colorSel < 0)                           // Si al reducir se obtiene un índice negativo se pone a 2.
        colorSel = 2;
    }
    else{                                         // Se está modificando un valor.
      if (colorRGB[colorSel] > 0)                 // Si no se ha llegado a 0 se decrementa el valor.
        colorRGB[colorSel]--;
    }
    actualizaPantalla();
  }                 
  for (uint16_t i = 0; i < ledCount; i++) {     // Recorre todos los LEDs.
    colors[i] = rgb_color(colorRGB[0], colorRGB[1], colorRGB[2]);   // Ajusta el color deseado de cada LED.
  }
  ledStrip.write(colors, ledCount, brightness); // Envía el color al LED. ¡Hasta que no se hace esto el color no cambia!
  delay(10);                                    // Espera 10 segundos antes de repetir el ciclo.
}

// Esta función se encarga de actualizar la pantalla al completo.
void actualizaPantalla(){
  tft.fillScreen(TFT_BLACK);                    // Se pone la pantalla completamente negra.
  tft.setTextColor(TFT_RED,TFT_BLACK);          // Se establece el color de la letra en rojo con fondo negro.
  tft.setCursor(35, 4);                         // Se establece el cursor en la posición x=35, y=4.
  tft.printf("Rojo: %d", colorRGB[0]);          // Se escribe "Hola mundo!" en la pantalla.
  tft.setCursor(35, 60);                        // Se establece el cursor en la posición x=35, y=60.
  tft.setTextColor(TFT_GREEN,TFT_BLACK);        // Se establece el color de la letra en verde con fondo negro.
  tft.printf("Verde: %d", colorRGB[1]);         // Se escribe "Hola mundo!" en la pantalla.
  tft.setCursor(35, 116);                       // Se establece el cursor en la posición x=35, y=116.
  tft.setTextColor(TFT_BLUE,TFT_BLACK);         // Se establece el color de la letra en azul con fondo negro.
  tft.printf("Azul: %d", colorRGB[2]);          // Se escribe "Hola mundo!" en la pantalla.
  if (modifica)                                 // Si se está modificando un valor se dibuja un triángulo, en caso contrario un círculo.
    tft.fillTriangle(27,2*(colorSel+1) + (52*colorSel)+26, 7, 2*(colorSel+1) + (52*colorSel)+16, 7, 2*(colorSel+1) + (52*colorSel)+36,TFT_YELLOW);
  else
    tft.fillCircle(17, 2*(colorSel+1) + (52*colorSel)+26, 10, TFT_YELLOW);
}

void unClick(){
  modifica = !modifica;                         // Cambia el estado de modificacion.
  actualizaPantalla();
}
