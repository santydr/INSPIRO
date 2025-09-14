# Ejercicio 7: Reloj conectado
Esta práctica tiene como objetivo que el alumno aprenda las posibilidades de conexión del microcontrolador ESP32-S3 integrado en el dispositivo T-embed.

El ESP32-S3 integrado dispone de conexión WiFi 2.4GHz y Bluetooth Low Energy v5. Las características anteriormente mencionadas abren un amplio abanico de posibilidades de interconexión. Para que el alumno pueda aprender a utilizarlas se presenta la realización de un reloj básico conectado a internet.
Como en casos anteriores, con el objetivo de simplificar el proceso se hará uso de varias librerias:
- Para la conexión WiFi se utilizará la librería WiFi que se encuentra integrada en Arduino por lo que no es necesaria ninguna instalación adicional. Únicamente es necesario importarla al inicio del programa para poder utilizarla.
- La gestión de las fechas y las horas se realiza mediante la librería [ESP32Time](https://github.com/fbiego/ESP32Time). Tenga en cuenta que al igual que pasaba con los botones, la gestión de fechas y horas puede parecer a priori mucho más sencilla de lo que es realmente. Por este motivo se recomienda encarecidamente hacer uso de librerias que simplifiquen este proceso.

El primer paso es la configuración de los datos del punto de acceso, así como del servidor NTP encargado de la sincronización de la hora. Posteriormente en **setup** se procede tanto al intento de conexión al punto de acceso WiFi como de la pantalla.
> Observe que antes de terminar la función **setup** se realiza la desconexión de la red. Esto se hace para ahorrar energía ya que una vez sincronizados, el reloj interno (RTC) del ESP32 se encargará de mantener el reloj en hora y la conexión es WiFi es costosa energéticamente hablando.

La función **loop** únicamente se encarga de refrescar la pantalla con la hora nueva siempre que al menos haya pasado un minuto.
## Ejercicios propuestos
- Modifique el programa suministrado para que se muestren los segundos transcurridos.
- Modifique el programa anterior para que se muestre también la fecha.
- Modifique el programa anterior para que muestre una tenue luz blanca en los LEDs si la hora está entre las 21:00 y las 23:00. Adicionalmente, debe apagar la pantalla entre las 23:00 y las 7:00. Si se produce una pulsación del botón debe encender la pantalla durante 5 segundos.

## Ejercicios de profundización
- Modifique el programa anterior para permitir al usuario introducir una hora de alarma. El dispositivo debe encender la pantalla y los LEDS en blanco a la hora seleccionada.
- Modifique el programa anterior para permitir al usuario modificar la hora manualmente.

## Enlaces de interés
El ESP32-S3 es un dispositivo potente y de bajo coste lo que ha hecho muy popular. Por este motivo, es sencillo encontrar una amplia variedad de recursos en internet. Adicionalmente, el dispositivo T-embed integra una cantidad de hardware que lo hace altamente adaptable. Entre estas posibilidades se encuentran: Pantalla TFT a color, LEDs RGB, encoder incremental, botón fisico, conector y circuito de carga y medición de bateria le litio, lector de tarjetas microSD, micrófono, altavoz, conectores de expansión, etc. Algunos de estos elementos se han explorado a lo largo de los ejercicios propuestos, otros se dejan a la curiosidad del estudiante. En cualquier caso, a continuación se enumeran una cantidad de recursos muy recomendables para un alumno que desee adentrarse en las posibilidades de este dispositivo:

- [Repositorio oficial T-embed](https://github.com/Xinyuan-LilyGO/T-Embed)
- [Hoja de datos del ESP32-S3](https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf)
- [FreeRTOS en ESP32-S3](https://docs.espressif.com/projects/esp-idf/en/stable/esp32s3/api-reference/system/freertos.html)
- [Librería Arduino audio tools](https://github.com/pschatzmann/arduino-audio-tools)
- [Librería gráfica LVGL](https://lvgl.io/)

## Propuestas finales
Una vez que el alumno haya investigado las posibilidades del dispositivo, se le anima a ir más allá en el uso de este. A continuación se listan algunas posibilidades que pueden ayudar a poner a prueba las habilidades adquiridas por el alumno, así como incentivar su imaginación:

- Cree un programa que haga las funciones de reloj despertador con alarma acústica integrada.
- Cree un programa que haga las funciones de reproductor mp3 y webradio.
- Cree un programa que integre los dos anteriores.
- Modifique los programas anteriores para crear un punto de acceso que muestre una página web que ofrezca la posibilidad de modificar la configuración: hora, alarma, color de fondo, etc.
- Cree un programa que permita obtener los datos del tiempo del dia de hoy a través de internet y mostrar los datos por pantalla.
- Estudie las posibilidades de interconexión del dispositivo con cualquier servicio online: Google calendar, Twitter, Spotify, etc.

El profesorado de la asignatura se despide con la esperanza de que estos ejercicios hayan sido de su interés. Además, aprovecha para recordarle que está a su disposición en caso de que necesite guía, ayuda o consejo durante su etapa formativa.
