# Ejercicio 4: Rotary encoder
Esta practica tiene como objetivo que el alumno se familiarice con el uso del [rotary encoder](https://www.ia.omron.com/support/guide/34/introduction.html) como sistema de entrada de información.

El encoder es un dispositivo que permite convertir el movimiento mecánico (normalmente rotatorio) en un valor digital. Existen versiones absolutas y relativas. Las primeras permiten saber exactamente la posición del encoder en todo momento. Las segundas permiten conocer únicamente el sentido del movimiento por lo que es necesario que se lleve la cuenta de la posición de otro modo. Debido a su menor coste y tamaño, los más utilizados en el mundo DIY son los encoder incrementales.

En este caso, el dispositivo incluye un rotary encoder incremental sin botón integrado. De nuevo se hará uso de una librería, en esta ocasión la elegida es [RotaryEncoder](https://github.com/mathertel/RotaryEncoder). Tal y como se ha venido haciendo, es necesario proporcionar los pines del encoder al crear el objeto. Además, es necesario incluir el modo de operación (este modo dependerá del encoder y el conexionado elegido). 
> En este caso, TWO03 indica 2 pasos con un latch en las posiciones 0 y 3. No es necesario entrar en el funcionamiento concreto, si lo desea puede probar a cambiarlo por alguna de las otras opciones FOUR3 o FOUR0.

De nuevo, al no hacer uso aún de la pantalla se hará uso de la conexión serie que deberá iniciarse en la funcion **setup**.
De forma muy parecida a como se hacia con el botón, es necesario actualizar el valor del encoder cada poco tiempo dentro de **loop** lo que permitirá obtener un valor de posición que indicará el sentido de giro mediante el signo, reservando el 0 para indicar que el encoder no ha cambiado su posición respecto a la última vez que se leyó su valor.
## Ejercicios propuestos
- Compruebe si el encoder tiene un límite físico de giro (como los potenciómetros) o no.
- Agregue una variable que cuente cuantos pasos se ha movido el encoder. Deberá comenzar en 0 e incrementarse o decrementarse según gire en una dirección u otra. Cuente cuantos pasos hay en una vuelta completa del encoder.
- Cree un programa que integre los LEDs y permita modificar el color de los mismos mediante el giro del encoder.
## Ejercicios de profundización
- Modifique el programa anterior para que mediante la pulsación del boton se vaya saltando de LED en LED y mediante el encoder permita modificar el color del LED seleccionado.
