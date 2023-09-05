#include "led.h"

#include <M12864stk.h>

namespace button
{
  void initialize()
  {
    DDRB = 0x00;
    PORTB = 0xff;
  }

  uint8_t read(uint8_t pin)
  {
    return !bitRead(PINB, pin);
  }

  uint8_t read()
  {
    return PINB ^ 0xff;
  }
}
