#include "led.h"

#include <M12864stk.h>

namespace led
{
  void initialize()
  {
    DDRC = 0xff;
    PORTC = 0xff;
  }

  void clear(uint8_t pin)
  {
    bitSet(PORTC, pin);
  }

  void set(uint8_t pin)
  {
    bitClear(PORTC, pin);
  }

  void write(uint8_t value)
  {
    PORTC = value ^ 0xff;
  }

  void write(uint8_t pin, uint8_t value)
  {
    bitWrite(PORTC, pin, !value);
  }

  uint8_t read()
  {
    return PORTC ^ 0xff;
  }

  uint8_t read(uint8_t pin)
  {
    return !bitRead(PORTC, pin);
  }
}
