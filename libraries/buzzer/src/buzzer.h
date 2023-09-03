#ifndef M12864STK_BUZZER_H
#define M12864STK_BUZZER_H

/**
 * The panel has a buzzer.
 * PG3 should be connected with a jumper to enable the buzzer.
 * Buzzer is making a sound if the port value is high.
 * PORTG3 - buzzer
 */
namespace buzzer
{
  /**
   * Initializes PORTC to output and turns off all LEDs.
   */
  void initialize();
  /**
   * Enables the buzzer.
   */
  void set();
  /**
   * Disables the buzzer.
   */
  void clear();
}

#endif