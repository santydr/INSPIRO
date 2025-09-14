# Ejercicio 4: Mostrar un archivo de imagen en pantalla
En este ejercicio representará un archivo de imagen mapa de bits en la pantalla. La inicialización de la pantalla y las librerías necesarias son las mismas que en el ejercicio anterior.

## Mostrar imágenes con la librería displayio
La librería [*displayio*](https://docs.circuitpython.org/en/latest/shared-bindings/displayio/index.html) dispone de la clase *.OnDiskBitmap* con la que se puede cargar una imagen mapa de bits desde la memoria a nuestro programa.

Luego, con la clase *.TileGrid* se crea el objeto a representar a partir de este mapa de bits.

## Copia de imagen de ejemplo al dispositivo
Para ejecutar el ejemplo, se proporciona una imagen en mapa de bits de ejemplo llamada [*imagen.bmp*](imagen.bmp). Esta imagen tiene ya el formato correcto (.bmp) y el tamaño adecuado para la pantalla (320x170 píxels). Hay que copiarla a la carpeta raíz del dispositivo (*CIRCUITPY*).

## Ejemplo
El código de ejemplo de este ejercicio ([T-Embed-CP-Ej4.py](T-Embed-CP-Ej4.py)) inicializa la pantalla y representa la imagen que tengamos guardada en la memoria con nombre *imagen.bmp*.

## Ejercicios propuestos
- Haz que el brillo de la pantalla comience al 100% y luego disminuya un 1% cada segundo, hasta llegar al 1% de brillo.
- Pintar un mensaje de texto encima de la imagen cuando el brillo llegue al mínimo. Fíjate en el ejemplo 3 para recordar cómo se muestra texto en la pantalla.
