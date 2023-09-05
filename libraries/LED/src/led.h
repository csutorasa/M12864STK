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
    * @return LED statues
    */
  uint8_t read();
  /**
    * Reads the selected LED status.
    * @param pin Pin of the LED
    * @return LED statues
    */
  uint8_t read(uint8_t pin);
  /**
    * Writes all LED statuses.
    * @param value On/Off status values for each pin
    */
  void write(uint8_t value);
  /**
    * Writes a LED status.
    * @param pin Pin of the LED
    * @param value On/Off status value
    */
  void write(uint8_t pin, uint8_t value);
}

#endif