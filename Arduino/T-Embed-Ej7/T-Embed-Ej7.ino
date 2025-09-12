/*************************************************************************************************************
 *                                                                                                           *
 * Título: Ejemplo_7 - Reloj conectado.                                                                      *
 * Autor: Santiago Díaz Romero.                                                                              *
 * Objetivo: Crear un reloj conectado a internet.                                                            *
 *                                                                                                           * 
 *************************************************************************************************************/

// Se importa la librería RotaryEncoder que permite controlar el encoder de forma sencilla.
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <ESP32Time.h>

// Se definen los pines asociados a la pantalla.
#define PIN_LCD_BL            15
#define PIN_LCD_DC            13
#define PIN_LCD_CS            10
#define PIN_LCD_CLK           12
#define PIN_LCD_MOSI          11
#define PIN_LCD_RES           9

//Se define el pin de encendido de la pantalla. (Obtenidos de la web del fabricante).
#define PIN_POWER_ON          46

TFT_eSPI tft = TFT_eSPI(170, 320);    // Se crea una variable tft que es un objeto de tipo TFT_eSPI de tamaño 170 x 320 pixeles.
ESP32Time rtc;                        // Se crea el objeto reloj de tiempo real (RTC Real Time CLock);

const char* ssid= "Nala";
const char* password= "NocheGordito1";

const char* ntpServer= "pool.ntp.org";
const long gmtOffset_sec = 1*3600;
const int daylightOffset_sec = 1*3600;

void setup() {
  pinMode(PIN_POWER_ON, OUTPUT);                  // Configura el pin de encendido como salida.
  digitalWrite(PIN_POWER_ON, HIGH);               // Enciende la pantalla y los LEDs.
  tft.begin();                                    // Se inicia la pantalla.
  tft.setRotation(3);                             // Se establece la rotación de la pantalla. Depende de cómo se oriente el dispositivo.
  tft.setTextFont(4);                             // Se establece la fuente en 2 (Alfabeto limitado, tamaño medio 26px).
  //tft.setTextSize(2);                             // Se establece el tamaño de la letra en 2x (52px).
  tft.fillScreen(TFT_BLACK);                    // Se pone la pantalla completamente negra.
  tft.setTextColor(TFT_WHITE,TFT_BLACK);          // Se establece el color de la letra en rojo con fondo negro.
  tft.setCursor(5, 5);                         // Se establece el cursor en la posición x=35, y=4.
  tft.printf("Conectando a %s", password);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    tft.setCursor(5, 65);
    delay(1000);
    tft.print(".");
  }
  configTime (gmtOffset_sec, daylightOffset_sec, ntpServer);
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)){
    rtc.setTimeStruct(timeinfo);
  }
  WiFi.disconnect(true);
  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(7);
  tft.setTextSize(2);
  tft.setTextColor(TFT_GREEN,TFT_BLACK);
}
int lastMin=100;
void loop() {
  //tft.fillScreen(TFT_BLACK);
  int currentMin = rtc.getMinute();
  if (lastMin!=currentMin){
    lastMin = currentMin;
    tft.setCursor((320-tft.textWidth(rtc.getTime("%H:%M")))/2, 170/2-48);
    tft.print(rtc.getTime("%H:%M"));
  }
  delay(100);
}
