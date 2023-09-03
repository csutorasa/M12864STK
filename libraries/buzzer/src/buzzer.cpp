#include "buzzer.h"

#include <Arduino.h>

namespace buzzer
{
  void initialize()
  {
    bitSet(DDRG, 3);
    bitClear(PORTG, 3);
  }

  void set()
  {
    bitSet(PORTG, 3);
  }

  void clear()
  {
    bitClear(PORTG, 3);
  }
}
