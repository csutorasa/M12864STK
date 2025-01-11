#ifndef M12864STK_LED_H
#define M12864STK_LED_H

#include <stdint.h>

/**
 * The panel has 8 LEDs named LED1 to LED8.
 * LED-EN should be connected with a jumper to enable LEDs,
 * so PORTC is connected to the LEDs of the panel.
 * LEDs are emitting light if the port value is low.
 * PORTC0 - LED1
 * PORTC1 - LED2
 * PORTC2 - LED3
 * PORTC3 - LED4
 * PORTC4 - LED5
 * PORTC5 - LED6
 * PORTC6 - LED7
 * PORTC7 - LED8
 */
namespace led
{
  /**
   * Initializes PORTC to output and turns off all LEDs.
   */
  void initialize();
  /**
    * Turns off the LED.
    * @param pin Pin of the LED
    */
  void clear(uint8_t pin);
  /** 
    * Turns on the LED.
    * @param pin Pin of the LED
    */
  void set(uint8_t pin);
  /**
    * Reads all LED statues.
    * Highest bit is LED1, lowest bit is LED8.
    * Bit value is 1 if the LED is on, 0 if it is off.
    * @return LED statues
    */
  uint8_t read();
  /**
    * Reads the selected LED status.
    * @param pin Pin of the LED
    * @return 1 if the LED is on, 0 if it is off
    */
  uint8_t read(uint8_t pin);
  /**
    * Writes all LED statuses.
    * Highest bit is LED1, lowest bit is LED8.
    * Bit value is 1 if the LED is on, 0 if it is off.
    * @param value bitmap of LEDs
    */
  void write(uint8_t value);
  /**
    * Writes a LED status.
    * @param pin Pin of the LED
    * @param value 1 if the LED is on, 0 if it is off
    */
  void write(uint8_t pin, uint8_t value);
  /**
   * Pin of LED1.
   */
  static int const LED1 = 0;
  /**
   * Pin of LED2.
   */
  static int const LED2 = 1;
  /**
   * Pin of LED3.
   */
  static int const LED3 = 2;
  /**
   * Pin of LED4.
   */
  static int const LED4 = 3;
  /**
   * Pin of LED5.
   */
  static int const LED5 = 4;
  /**
   * Pin of LED6.
   */
  static int const LED6 = 5;
  /**
   * Pin of LED7.
   */
  static int const LED7 = 6;
  /**
   * Pin of LED8.
   */
  static int const LED8 = 7;
}

#endif