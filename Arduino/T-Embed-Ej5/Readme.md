# Ejercicio 3: Pantalla LCD
Esta practica tiene como objetivo que el usuario se familiarice con el uso de la pantalla TFT como dispositivo de salida de información.

El dispositivo integra un pantalla TFT de 170x320 píxeles que hace uso de un controlador [ST7789](https://www.waveshare.com/w/upload/a/ae/ST7789_Datasheet.pdf). El uso de las pantallas es similar al visto en las prácticas de la asignatura. Es decir se hace uso de una matriz de colores qn que cada uno corresponde a un color. Esta forma de trabajar, una vez llevada a su implementación hardware es compleja por lo que se va a hacer uso de una librería para poder abstraerse de todo ese funcionamiento. La librería elegida es [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI). Esta librería tiene un rendimiento excepcionalmente bueno comparado con otras librerías. Además, posee una compatibilidad con un amplio abanico de pantallas. Como elemento negativo, requiere una configuración medianamente compleja antes de poder ser utilizado.
> Para evitar añadir complejidad se ha incluido la librería correctamente configurada para su uso. El proceso de instalación en este caso es ligeramente dirente:
> - Cierre Arduino.
> - Busque la carpeta de libraries de arduino. Por defecto se encuentra en *C:\Users\<usuario>\Documents\Arduino\libraries*.
> - Descomprima el fichero .zip proporcionado en esta carpeta.
> - Abra Arduino.

Una vez realizados los pasos anteriores, el proceso es muy similar al usado conanterioridad: importar la librería, indicar los pines y crear un objeto pantalla. **Recuerde:** es necesario poner a 1 el pin de POWER_ON.

En este caso, la función **setup** se encarga de la inicialización de la pantalla así como de la configuración de algunos parámetros iniciales como son la orientación de la pantalla y el tipo de letra.

Por su parte, **loop** realiza una serie de impresiones en la pantalla para demostrar algunas de las posibilidades que ofrece la librería.

> Tenga en cuenta que el uso de una pantalla a color es un proceso computacionalmente costoso. Por este motivo debe analizar muy bien la necesidad de las mismas en sus proyectos y seleccionar un microcontrolador con la potencia adecuada. Además, requiere una cantidad de memoria **grande** (en terminos de microcontrolador) por lo que es posible que necesite algún tipo de memoria de almacenamiento extra.

## Ejercicios propuestos
- Agregue un segundo print tras "Hola mundo!". ¿Dónde aparece el nuevo texto?
- Modifique el programa para que el texto añadido se muestre en una nueva línea.
- Modifique a su antojo las coordenadas. ¿Dónde se encuentra el origen de coordenadas?
- Modifique el programa para que dibuje un circulo sobre otro. ¿Cuál prevalece?
## Ejercicios de profundización
- Cree un programa que dibuje un circulo de 10 píxeles de diámetro que se mueva a la derecha 3 píxeles por segundo. ¿Que ocurre?¿Cómo podría solucionarlo?
- Investigue los ficheros *User_Setup.h* y *TFT_config.h* en la carpeta *C:\Users\<usuario>\Documents\Arduino\libraries*. ¿Puede identificar qué líneas debe modificar para seleccionar otro tamaño de pantalla, controlador, etc?
- Investigue sobre las posibilidades que ofrece la librería en el [repositorio de la misma](https://github.com/Bodmer/TFT_eSPI) y [aquí](https://doc-tft-espi.readthedocs.io/starting/).
> El repositorio oficial de la librería carece de muchas explicaciones no obstante leyendo el fichero .h es posible encontrar algunas funciones autoexplicativas. Por otro lado, el segundo enlace proporcionado ofrece información más accesible pero incompleta de las funciones y funcionalidades disponibles.
