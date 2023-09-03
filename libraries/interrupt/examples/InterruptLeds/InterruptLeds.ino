#include <led.h>
#include <interrupt.h>

volatile uint8_t value = 0;

void blink()
{
  value = ~value;
}

int main()
{
  led::initialize();
  interrupt0::initialize();
  interrupt0::onInterrupt(&blink);
  sei();
  while (true)
  {
    led::write(value);
  }
  return 0;
}
