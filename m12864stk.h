#ifndef M12864STK
#define M12864STK

#include <inttypes.h>
#include <arduino.h>

#define F_CPU 8000000L

class UART
{
  public:
    // Starts UART communication.
    void begin(uint16_t baud);
    // Writes a byte to UART.
    // @param data Byte to write
    void print(uint8_t data);
    // Reads a byte from UART.
    uint8_t read();
    // Checks if UART has available data to read.
    uint8_t available();
};

class Button
{
public:
  Button();
  // Gets the state of the button.
  uint8_t get(uint8_t pin);
  // Gets the state of all buttons.
  uint8_t read();
};

class LED
{
  public:
    LED();
    // Turns off the LED.
    // @param pin Pin of the LED
    void clear(uint8_t pin);
    // Turns on the LED.
    // @param pin Pin of the LED
    void set(uint8_t pin);
    // Reads all LED statues.
    uint8_t read();
    // Reads the selected LED status.
    // @param pin Pin of the LED
    uint8_t read(uint8_t pin);
    // Writes all LED statuses.
    // @param value On/Off status values for each pin
    void write(uint8_t value);
    // Write a LED status.
    // @param pin Pin of the LED
    // @param value On/Off status value
    void write(uint8_t pin, uint8_t value);
};

class Buzzer
{
public:
  Buzzer();
  // Enables the buzzer.
  void set();
  // Disables the buzzer.
  void clear();
};

class Timer0 {
  void (*event)();
  public:
    // Starts the timer.
    // @param limit The Counter overflow value.
    void start(uint8_t limit);
    // Sets the event of the timer.
    // @param event Event to be called after the timer overflows.
    void onTick(void (*event)());
    // This function should never be used.
    void tick();
    // Stops the timer.
    void stop();
};

class Display
{
  const uint8_t numbers[10]  = {
    0b00000011, // 0
    0b10011111, // 1
    0b00100101, // 2
    0b00001101, // 3
    0b10011001, // 4
    0b01001001, // 5
    0b01000001, // 6
    0b00011111, // 7
    0b00000001, // 8
    0b00001101 // 9
  };
  const uint8_t letters[26] = {
    0b00010001, // A
    0b11000001, // B
    0b01100011, // C
    0b10000101, // D
    0b01100001, // E
    0b01110001, // F
    0b01000011, // G
    0b11010001, // H
    0b11110011, // I
    0b10001111, // J
    0b10010001, // K
    0b11100011, // L
    0b00010011, // M
    0b11010101, // N
    0b11000101, // O
    0b00110001, // P
    0b00011001, // Q
    0b11110101, // R
    0b01001001, // S
    0b11100001, // T
    0b10000011, // U
    0b11000111, // V
    0b01000111, // W
    0b10010001, // X
    0b10001001, // Y
    0b00100101 // Z
  };
    uint8_t data[8] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    uint8_t current;
  public:
    Display();
    // Prints a text into the display.
    // @param str Text
    void print(String str);
    // Prints a character into the display.
    // @param ch Character
    // @param pos Position of the character
    void print(char ch, uint8_t pos);
    // Refreshes the LEDs of the display.
    // This must be called peroidcally
    void refresh();
};

extern Button button;
extern UART uart;
extern LED led;
extern Display display;
extern Buzzer buzzer;
extern Timer0 timer0;

#endif

//////////////////////////////////////////////////////////////////////////////////
// Documentation of board functions
//
// Display driver:
//
// 74HC138 http://www.nxp.com/documents/data_sheet/74HC_HCT138.pdf
//
// A0  1|-----|16 VCC
// A1  2|  U  |15 /Y0
// A2  3|     |14 /Y1
// /E1 4|     |13 /Y2
// /E2 5|     |12 /Y3
// E3  6|     |11 /Y4
// /Y7 7|     |10 /Y5
// GND 8|-----|9  /Y6
// 
// A0 - PORTA7
// A1 - PORTA6
// A2 - PORTA5
// E3 - PORTA4 (high active)
//
// 74HC595 http://www.nxp.com/documents/data_sheet/74HC_HCT595.pdf
//
// Q1  1|-----|16 VCC
// Q2  2|  U  |15 Q0
// Q3  3|     |14 DS
// Q4  4|     |13 /OE
// Q5  5|     |12 STCP
// Q6  6|     |11 SHCP
// Q7  7|     |10 /MR
// GND 8|-----|9  Q7S
//
// SHCP - PORTA1
// STCP - PORTA2
// DS - PORTA3
//
