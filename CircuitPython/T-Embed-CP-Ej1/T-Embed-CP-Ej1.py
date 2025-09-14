#############################################################################################################
#                                                                                                           #
# Título: CircuitPython_Ejemplo_1 - ¡Hola mundo!                                                            #
# Autor: Juan M. Montes Sánchez.                                                                            #
# Objetivo: Introducción y primera aproximación a CircuitPython con el dispositivo T-Embed.                 #
#                                                                                                           # 
#############################################################################################################

# --------------------
# Importamos las librerías necesarias
# --------------------
import time         # Necesaria para hacer esperas
# --------------------

time.sleep(1)           # Espera de un segundo
print("¡Hola Mundo!")   # Escribe un mensaje en la consola y en el puerto serie

while True:                 # Bucle infinito
    time.sleep(1)           # Espera de un segundo
    pass