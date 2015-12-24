Python Thermal Printer Library
==============================

Thermal printing library that controls the "micro panel thermal printer" sold in
shops like Adafruit and Sparkfun (e.g. http://www.adafruit.com/products/597). 
Mostly ported from Ladyada's Arduino library 
(https://github.com/adafruit/Adafruit-Thermal-Printer-Library) to run on
BeagleBone and Raspberry Pi.

If on BeagleBone or similar device, remember to set the mux settings
or change the UART you are using. To enable the defaults for example:

    # MUX SETTINGS (Ängström 2012.05 on BeagleBone) 
    echo 1 > /sys/kernel/debug/omap_mux/spi0_sclk
    echo 1 > /sys/kernel/debug/omap_mux/spi0_d0 

If on a Raspberry Pi and using the GPIO UART pins, remember to use a level shifter
between the printer (5V) and the RPi (3V3).

For more detailed step-by-step instructions see [this tutorial](http://geekgurldiaries.blogspot.fi/2012/12/little-box-of-geek-project.html).

UART can be changed by passing the device path to the constructor:
`p = printer.ThermalPrinter(serialport="/dev/ttyUSB0")`

Thanks to Matt Richardson for the initial pointers on controlling the
device via Python.

Author: 
Lauri Kainulainen

Contributors:
Jonathan Harlap
Owen Mundy
bodiedoo


Licensed under the MIT license
