# M128/64 STK

This project is an arduino library for my M128/64 STK board. It is a developer board with a ATMega128a micocontroller on it.

## How to use:
 * You need the latest sources as zip ([download](https://github.com/csutorasa/M12864STK/archive/master.zip)).
 * Open Arduino Studio.
 * Click Sketch/Include Library/Add .ZIP Library...
 * Select the file.
 * Done.
 
## Board configuration
If you have never used ATMega128a with Arduino Studio, you should add it to board configuration. It can be found in {installdirectory}/hardware/arduino/avr/boards.txt. You should add these lines to the file:
```
atmega128.name=ATmega128
atmega128.upload.using=usbasp
atmega128.upload.maximum_size=126976
atmega128.build.mcu=atmega128
atmega128.build.f_cpu=8000000L
atmega128.build.core=arduino
atmega128.build.variant=standard
atmega128.build.board=AVR_ATMEGA128
```

## Other downloads:
USBASP drivers for Windows: [download page](http://zadig.akeo.ie/)
Serial(RS232) driver for Windows: [download page](https://serialio.com/drivers-and-set-up-usb-rs-232-adapter-in-windows)
