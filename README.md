# M128/64 STK

This project is an arduino library for my M128/64 STK board.
It is a developer board with a ATMega128a micocontroller on it.

## Using the board

You need the latest [release](https://github.com/csutorasa/m12864stk/releases/download/1.0.0/m12864stk.zip).

Find your local data folder (on Windows it is in `%LOCALAPPDATA%` by default).
Open `{BASE_DIR}\Arduino15\packages\arduino\hardware\` directory.
Create `{BASE_DIR}\Arduino15\packages\arduino\hardware\m12864stk` direcotry and open it.
Create `{BASE_DIR}\Arduino15\packages\arduino\hardware\m12864stk\1.0.0` direcotry and open it.
Unzip `m12864stk.zip` into this directory.
Restart Arduino IDE.

## Using the libraries

You need the latest [release](https://github.com/csutorasa/m12864stk/releases/download/1.0.0/m12864stk.zip).
Unzip `m12864stk.zip` into a temporary directory.
Open `libraries` directory.
Create a zip archive from the library you want to use.
Use the [official guide] to add this zip to the libraries in Arduino IDE.

## Flashing

The device can be flashed via ISP.
A simple way is to flash the software with USBASP.
You will need [drivers](http://zadig.akeo.ie/) for using it.
