#ifndef M12864STK_BUTTON_H
#define M12864STK_BUTTON_H

#include <stdint.h>

/**
 * The panel has 8 buttons named KEY1 to KEY8.
 * PORTB is connected to the buttons of the panel.
 * Buttons are pushed if the port value is low.
 * PORTB0 - KEY1
 * PORTB1 - KEY2
 * PORTB2 - KEY3
 * PORTB3 - KEY4
 * PORTB4 - KEY5
 * PORTB5 - KEY6
 * PORTB6 - KEY7
 * PORTB7 - KEY8
 */
namespace button
{
  /**
   * Initializes PORTB to input.
   */
  void initialize();
  /**
   * Gets the state of the button.
   * @param pin Pin of the button
   * @return 1 if the button is pressed, 0 if it is released
   */ 
  uint8_t read(uint8_t pin);
  /**
   * Gets the state of all buttons as a number.
   * Highest bit is KEY1, lowest bit is KEY8.
   * Bit value is 1 if the button is pressed, 0 if it is released.
   * @return bitmap of buttons
   */ 
  uint8_t read();
  /**
   * Pin of KEY1.
   */
  static int const KEY1 = 0;
  /**
   * Pin of KEY2.
   */
  static int const KEY2 = 1;
  /**
   * Pin of KEY3.
   */
  static int const KEY3 = 2;
  /**
   * Pin of KEY4.
   */
  static int const KEY4 = 3;
  /**
   * Pin of KEY5.
   */
  static int const KEY5 = 4;
  /**
   * Pin of KEY6.
   */
  static int const KEY6 = 5;
  /**
   * Pin of KEY7.
   */
  static int const KEY7 = 6;
  /**
   * Pin of KEY8.
   */
  static int const KEY8 = 7;
}

#endif