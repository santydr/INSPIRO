#############################################################################################################
#                                                                                                           #
# Título: CircuitPython_Ejemplo_4 - Representar archivo de imagen en pantalla.                              #
# Autor: Juan M. Montes Sánchez.                                                                            #
# Objetivo: Aprender a representar un archivo de imagen en la pantalla de T-Embed.                          #
#                                                                                                           # 
#############################################################################################################

# --------------------
# Importamos las librerías necesarias
# --------------------
import time                             # Necesaria para hacer esperas
import board                            # Incluye elementos de la placa
import busio                            # Control de buses
import displayio                        # Necesaria para hacer esperas
from fourwire import FourWire           # Para manejo de un bus SPI cuatro hilos
from adafruit_st7789 import ST7789      # Manejo de pantalla ST7789. Necesario instalar.
import terminalio                       # Representar texto.
from adafruit_display_text import label # Representar texto. Necesario instalar.
# --------------------

# Primero hay que liberar la pantalla de cualquier otro uso
displayio.release_displays()

# Configuración de pines de la pantalla. Asignamos a cada señal su pin correspondiente.
tft_clk = board.IO12
tft_mosi = board.IO11
tft_cs = board.IO10
tft_dc = board.IO13
tft_rst = board.IO9
tft_bl = board.IO15

# Se inicia el bus SPI que usaremos para controlar la pantalla.
spi=busio.SPI(clock=tft_clk, MOSI=tft_mosi, MISO=None, half_duplex = False )

# Se configura el bus SPI en modo cuatro hilos.
display_bus = FourWire(spi, command=tft_dc, chip_select=tft_cs, reset=tft_rst)

# Configuración del display con la librería ST7789. Ancho, alto, rotación...
display = ST7789(

    display_bus,

    width=320,

    height=170,

    rowstart=0,

    colstart=35,

    rotation=90,

    backlight_pin=tft_bl,

)


# Ponemos un valor de brillo de pantalla del 50%
Brightvalue = 0.5
display.brightness = Brightvalue

# Representamos el display
splash = displayio.Group()
display.root_group = splash

# Cargamos una imagen mapa de bits
# - El archivo de imagen tiene que ser en formato mapa de bits (.bmp)
# - El tamaño del archivo tiene que coincidir con la pantalla (320x170 píxels)
# - Tendremos que copiar el archivo previamente a la memoria de T-Embed
odb = displayio.OnDiskBitmap('/imagen.bmp')    
pic = displayio.TileGrid(odb, pixel_shader=odb.pixel_shader)

# Se muestra la imagen
splash.append(pic)

while True:             # Bucle infinito
    time.sleep(1)       # Espera de un segundo
    pass