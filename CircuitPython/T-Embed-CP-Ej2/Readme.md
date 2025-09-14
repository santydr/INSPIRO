# Ejercicio 2: Botón y rotary encoder en CircuitPython
El dispositivo [T-embed](https://lilygo.cc/products/t-embed) dispone de un botón y un rotary encoder que permiten al usuario interactuar con el código.

## Librería board
Para hacer uso de los elementos del dispositivo tendremos que importar la libería [*board*](https://docs.circuitpython.org/en/latest/shared-bindings/board/index.html). Esta librería contiene los nombres de todos los pines del dispositivo y es única para cada tipo de placa.

En la siguiente imagen de la documentación de T-Embed están todos los nombres de los elementos que se usarán para inicializarlos haciendo uso de la librería. Por ejemplo, *board.IO0* hará referencia al botón y *board.IO1* y *board.IO2* al encoder.

![Elementos de T-Embed](imágenes/CP-Ej2_01.png)

## Librería digitalio
La libería [*digitalio*](https://docs.circuitpython.org/en/latest/shared-bindings/digitalio/index.html) permite inicializar y hacer uso del botón. Una vez inicializado podremos leer su valor con el método *.value*.

## Librería rotaryio
La libería [*rotaryio*](https://docs.circuitpython.org/en/latest/shared-bindings/rotaryio/index.html) permite inicializar y hacer uso del rotary encoder. El funcionamiento del encoder requiere de dos señales (encoder A y encoder B). Una vez inicializado se puede leer la posición del encoder con el método *.position*. Podemos saber si el giro ha sido hacia la izquierda o hacia la derecha siempre que tuviéramos guardada la posición anterior, comparando si la actual es mayor o menor que antes.

## Ejemplo de uso de botón y encoder
El código de ejemplo de este ejercicio ([T-Embed-CP-Ej2.py](T-Embed-CP-Ej2.py)) inicializa el botón y el encoder y luego muestra en la consola un mensaje cada vez que se pulsa el botón o se detecta un cambio de posición del encoder.


## Ejercicios propuestos
- Modifique el programa para que el mensaje sea distinto si el encoder gira hacia la derecha o hacia la izquierda.
