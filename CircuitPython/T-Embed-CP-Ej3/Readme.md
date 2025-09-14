# Ejercicio 3: Uso básico de la pantalla
En este ejercicio se hará un uso básico de la pantalla para representar figuras de color y texto.

## Librería board
De nuevo habrá que hacer uso de la librería board. La pantalla está conectada mediante un bus de comunicación SPI de cuatro hilos (*Four Wire SPI*). De la documentación del dispositivo T-Embed sabemos que los pines relacionados con la pantalla son los siguientes:
- CLK = board.IO12 (Señal *Clock* del bus SPI)
- MOSI = board.IO11 (Señal *MOSI* del bus SPI)
- CS = board.IO10 (Señal *Chip Select* del bus SPI)
- DC = board.IO13 (Señal *Data Command* del bus SPI)
- RST = board.IO9 (Señal *Reset* de la pantalla)
- BL = board.IO15 (*Back Light* o luz de fondo de la pantalla)

## Librería busio
La libería [*busio*](https://docs.circuitpython.org/en/latest/shared-bindings/busio/index.html) permite inicializar y hacer uso de un bus tipo I2C o SPI básico.

## Librería fourwire
La libería [*fourwire*](https://docs.circuitpython.org/en/latest/shared-bindings/fourwire/index.html) permite inicializar y hacer uso de un display conectado por un SPI de cuatro hilos. Requiere haber inicializado el bus SPI previamente con la librería *busio*.

## Librerías para uso de pantalla: displayio y adafruit_st7789
El modelo de pantalla del dispositivo T-Embed es el ST7789. Podemos hacer uso de la libería [*adafruit_st7789*](https://docs.circuitpython.org/projects/st7789/en/latest/) para representar información en la misma.

Es necesaria también la librería [*displayio*](https://docs.circuitpython.org/en/latest/shared-bindings/displayio/index.html).

## Librerías para texto: adafruit_display_text y terminalio
En el presente ejemplo también se va a representar texto. Se hará uso de las librerías [*terminalio*](https://docs.circuitpython.org/en/latest/shared-bindings/terminalio/index.html) y [*adafruit_display_text*](https://docs.circuitpython.org/projects/display_text/en/latest/api.html) para crear un texto y representarlo.

La librería *adafruit_display_text* tiene una lista de opciones muy extensa para hacer todo tipo de efectos gráficos con texto de forma sencilla.

## Instalación de librerías
Hasta ahora se ha hecho uso de librerías incluidas (*core*). Sin embargo, en este ejemplo hay dos librerías que NO están preinstaladas en T-Embed: *adafruit_st7789* y *adafruit_display_text*. Ambas son parte del pack de librerías CircuitPython de Adafruit que está publicado en el siguiente [enlace](https://github.com/adafruit/Adafruit_CircuitPython_Bundle). Las librerías CircuitPython tienen extensión *.mpy*.

Por comodidad, se ha incluido un archivo comprimido en este proyecto solo con estas dos librerías: [T-Embed-CP-Ej3_Libraries.zip](T-Embed-CP-Ej3_Libraries.zip).

Para instalarlas, simplemente hay que descargar este archivo comprimido .zip y extraer tanto la carpeta *adafruit_display_text* como el archivo *adafruit_st7789.mpy* dentro de la carpeta *lib* del dispositivo T-Embed (accediendo a su carpeta CIRCUITPY/lib desde el navegador de archivos del sistema).

## Ejemplo de uso de la pantalla
El código de ejemplo de este ejercicio ([T-Embed-CP-Ej3.py](T-Embed-CP-Ej3.py)) inicializa la pantalla y representa dos rectángulos y un texto de color.

## Ejercicios propuestos
- Haz modificaciones para cambiar el tamaño, color y posición de los elementos. ¿Qué pasa si los representas en orden distinto?
- Cambia el valor de brillo de la pantalla.

## Ejercicio de ampliación
- Modifica el programa para que, en lugar del texto, aparezca en la pantalla un contador que se vaya incrementando cada segundo.
