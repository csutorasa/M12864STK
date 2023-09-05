# M128/64 STK

This project is an arduino library for my M128/64 STK board.
It is a developer board with a ATMega128a micocontroller on it.

## Using the board

Use the [board manager](https://support.arduino.cc/hc/en-us/articles/360016466340-Add-or-remove-third-party-boards-in-Boards-Manager)
with the custom board manager URL https://raw.githubusercontent.com/csutorasa/M12864STK/master/package_index.json.

## Using the libraries

You need to explore the latest [release](https://github.com/csutorasa/M12864STK/releases/).
Find the library you need and download the zip archive.
Use the [official guide](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries) to add this zip to the libraries in Arduino IDE.

## Flashing

The device can be flashed via ISP.
A simple way is to flash the software with USBASP.
You will need [drivers](http://zadig.akeo.ie/) for using it.
