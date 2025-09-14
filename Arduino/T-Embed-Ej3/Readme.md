# Ejercicio 3: Uso del botón
Esta practica tiene como objetivo que el alumno se familiarice con el uso del botón como sistema de entrada de información.

El uso de un botón físico como sistema de entrada puede parecer a priori muy sencillo. Este plantemiento puede ser un error ya que a menudo se olvidan o ignoran las posibles complicaciones asociadas al uso de un dispotivo tan "simple". Entre ellos se encuentran: rebotes, manejo de tiempos de presión, etc. Para simplificar el proceso de uso del mismo, se hará uso de la popular librería OneButton. Para instalar la libraría anteriormente mecionada debe seguir los mismos pasos que en el ejercicio anterior, sólo que esta vez debe escribir OneButton en el campo de búsqueda.

Una vez instalada e importada la librería (como en el ejercicio anterior), es necesario crear un objeto de tipo OneButton. De nuevo para hacer esto, es necesario indicar el pin al que está conectado el botón (consultar fabricante).
![Pines T-embed](https://github.com/Xinyuan-LilyGO/T-Embed/raw/main/image/T-Embed1.png)
En este caso, puede comprobar que es el pin 0 (aparece junto a los pines asociados al encoder).
Para poder obtener una realimentación de la pulsación del botón se escribirán mensajes por el puerto serie. Para ello en **setup** se configurará el puerto serie como se vio en el primer ejercicio. Adicionalmente, es necesario indicar que acciones del botón se quieren asociar. La librería se encargará de forma autónoma de comprobar si se ha producido el comportamiento deseado. En este caso se van a asociar (vigilar) las siguientes acciones:
- Click.
- Doble click.
- Click largo.
Cuando se produzca cada uno de estos eventos/acciones, el programa ejecutará las acciones que se encuentren en la función que se le pasó como parámetro al asociarlas.
En la función **loop** únicamente es necesario comprobar periódicamente el estado del botón llamando a *.tick*.
> La librería permite más acciones, así como la pesonalización de algunos parámetros. Le animamos a consultar [la guía de referencia de la librería](https://github.com/mathertel/OneButton).

## Ejercicios propuestos
- Modifique incremente el valor de espera (delay) en **loop** y observe como se comporta el dispositivo.
- Integre los LEDs vistos en el ejercicio anterior para que al pulsar el botón se enciendan o apaguen (alternativamente).
- Modifique el apartado anterior para que un click encienda los LEDs y doble click los apague.
- Modifique el código para que un click cambie el color de los LEDs.
## Ejercicios de profundización
- Modifique el apartado anterior para que un click largo modifique los colores de los LEDs según el tiempo de pulsación.
- Intente obtener el estado del botón sin hacer uso de la libreria. Una vez realizado este apartado, intente repetir todos los ejericios sin hacer uso de la librería.
