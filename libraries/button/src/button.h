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
   * @return state of button
   */ 
  uint8_t read(uint8_t pin);
  // Gets the state of all buttons.
  /**
   * Gets the state of all buttons.
   * @return state of buttons
   */ 
  uint8_t read();
}

#endif