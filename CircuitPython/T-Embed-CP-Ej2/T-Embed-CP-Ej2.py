# SPDX-FileCopyrightText: 2021 ladyada for Adafruit Industries

# SPDX-License-Identifier: MIT


"""

This test will initialize the display using displayio and draw a solid green

background, a smaller purple rectangle, and some yellow text.

"""

import board

import busio

import displayio

import digitalio

import rotaryio

import time

import terminalio

from adafruit_display_text import label

from fourwire import FourWire

from adafruit_st7789 import ST7789


# Release any resources currently in use for the displays

displayio.release_displays()

# Configuramos botón como entrada
button = digitalio.DigitalInOut(board.IO0)

# Configuramos encoder con la librería rotaryio
encoder = rotaryio.IncrementalEncoder(board.IO2, board.IO1, divisor=2)
last_position = encoder.position # Esta variable global guardará la última posición del encoder



# Configuración de pines de la pantalla. Asignamos a cada señal su pin correspondiente.
tft_clk = board.IO12
tft_mosi = board.IO11
tft_cs = board.IO10
tft_dc = board.IO13
tft_rst = board.IO9
tft_bl = board.IO15

# Se inicia el bus SPI que usaremos para controlar la pantalla.
spi=busio.SPI(clock=tft_clk, MOSI=tft_mosi, MISO=None, half_duplex = False )
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


# Valor inicial de brillo de la pantalla al 50%
Brightvalue = 0.5
display.brightness = Brightvalue

# Make the display context

splash = displayio.Group()

display.root_group = splash

# --------------------
# PINTAR FONDO VERDE
# --------------------
color_bitmap = displayio.Bitmap(320, 170, 1) # Definimos mapa de bits del tamaño de la pantalla
color_palette = displayio.Palette(1) # Creamos una paleta de color
color_palette[0] = 0x00FF00  # Añadir a la paleta el valor hexadecimal para verde puro

# Creamos el rectángulo de fondo con los valores definidos y se muestra en la pantalla
bg_sprite = displayio.TileGrid(color_bitmap, pixel_shader=color_palette, x=0, y=0)
splash.append(bg_sprite)
# --------------------

# --------------------
# PINTAR RECUADRO ROJO
# --------------------
inner_bitmap = displayio.Bitmap(280, 130, 1) # Definimos mapa de bits más paqueño que el tamaño de la pantalla
inner_palette = displayio.Palette(1) # Creamos una paleta de color nueva
inner_palette[0] = 0xFF0000  # Añadir a la paleta el valor hexadecimal para rojo puro

# Creamos el rectángulo rojo con los valores definidos y se muestra en la pantalla.
# Importante desplazar la posición de origen para que quede centrado.
inner_sprite = displayio.TileGrid(inner_bitmap, pixel_shader=inner_palette, x=20, y=20)
splash.append(inner_sprite)
# --------------------

# --------------------
# PINTAR TEXTO
# --------------------
# Se define el espacio para el texto
text_group = displayio.Group(scale=5, x=55, y=85)

text = "INSPIRO" # El texto que se quiere mostrar
color= 0x00FF00 # Valor hexadecimal del color verde puro

# Se crea el objeto de texto (fuente, texto y color)
text_area = label.Label(terminalio.FONT, text=text, color=color)

# Añadimos el texto al espacio creado
text_group.append(text_area) 

# Se muestra el objeto de texto en la pantalla
splash.append(text_group)
# --------------------


# Load an image

# odb = displayio.OnDiskBitmap('/buddies.bmp')
# pic = displayio.TileGrid(odb, pixel_shader=odb.pixel_shader)
# splash.append(pic)

colorchanger=0

while True:
        
    # Button handling
    if not button.value:
        print("Button pressed!")
    current_position = encoder.position
    position_change = current_position - last_position
    if position_change > 0:
        if Brightvalue < 0.9:
            Brightvalue += 0.1
            display.brightness = Brightvalue
            print(f"Brightness increased to {Brightvalue:.1f}")
        else:
            print("Brightness is already at maximum")
    elif position_change < 0:
        if Brightvalue > 0.1:
            Brightvalue -= 0.1
            display.brightness = Brightvalue
            print(f"Brightness decreased to {Brightvalue:.1f}")
        else:
            print("Brightness is already at minimum")
    last_position = current_position
    time.sleep(0.1)
    pass