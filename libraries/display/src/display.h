#ifndef M12864STK_DISPLAY_H
#define M12864STK_DISPLAY_H

#include <stdint.h>

/**
 * The panel has 2 F3461BH 8-digit displays.
 * One of them is driven by a 74HCT138,
 * the other is driven by a 74HCT595.
 * Display driver:
 *
 * A0  1|-----|16 VCC
 * A1  2|  U  |15 /Y0
 * A2  3|     |14 /Y1
 * /E1 4|     |13 /Y2
 * /E2 5|     |12 /Y3
 * E3  6|     |11 /Y4
 * /Y7 7|     |10 /Y5
 * GND 8|-----|9  /Y6
 * 
 * A0 - PORTA7
 * A1 - PORTA6
 * A2 - PORTA5
 * E3 - PORTA4 (high active)
 *
 * Q1  1|-----|16 VCC
 * Q2  2|  U  |15 Q0
 * Q3  3|     |14 DS
 * Q4  4|     |13 /OE
 * Q5  5|     |12 STCP
 * Q6  6|     |11 SHCP
 * Q7  7|     |10 /MR
 * GND 8|-----|9  Q7S
 *
 * SHCP - PORTA1
 * STCP - PORTA2
 * DS - PORTA3
 */
namespace display
{
  /**
   * Initializes PORTA to output and turns off the display.
   */
  void initialize();
  /**
   * Prints a text into the display.
   * @param str Text
   */
  void print(const char* str);
  /**
   * Prints a character into the display.
   * @param ch Character
   * @return mask for the character
   */
  uint8_t getMask(char ch);
  /**
   * Prints a character into the display.
   * @param ch Character
   * @param pos Position of the character
   */
  void print(char ch, uint8_t pos);
  /**
   * Refreshes the LEDs of the display for a single digit.
   */
  void refresh(uint8_t pos);
  /**
   * Refreshes the LEDs of the display.
   */
  void refresh();
}

#endif