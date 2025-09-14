#############################################################################################################
#                                                                                                           #
# Título: CircuitPython_Ejemplo_2 - Uso del botón y el rotary encoder                                       #
# Autor: Juan M. Montes Sánchez.                                                                            #
# Objetivo: Aprender el uso del botón y el rotary encoder en CircuitPython.                                 #
#                                                                                                           # 
#############################################################################################################

# --------------------
# Importamos las librerías necesarias
# --------------------
import time             # Necesaria para hacer esperas
import board            # Incluye elementos de la placa
import digitalio        # Para entrada/salida digital
import rotaryio         # Para uso de encoder
# --------------------


# Configuramos botón como entrada
button = digitalio.DigitalInOut(board.IO0)

# Configuramos encoder con la librería rotaryio
encoder = rotaryio.IncrementalEncoder(board.IO2, board.IO1, divisor=2)

last_position = encoder.position # Esta variable global guardará la última posición del encoder

# Bucle infinito
while True:
        
    # Si el botón está pulsado envia un mensaje
    if not button.value:
        print("¡Botón pulsado!")
    
    # Guarda la posición actual del encoder
    current_position = encoder.position
    
    # Se compara con la posición anterior
    position_change = current_position - last_position
    
    # Si la posición es distinta, ha girado
    if position_change != 0:
        print("¡Giro del encoder!")
    
    # Actualiza la última posición a la actual
    last_position = current_position
    
    # Espera antes de reiniciar el bucle
    time.sleep(0.1)
    pass