#include <timer.h>
#include <led.h>

volatile uint8_t value = 0;
volatile uint8_t x = 0;

void blink()
{
  x++;
  if (x == 255)
  {
    value = ~value;
  }
}

int main()
{
  led::initialize();
  TIMSK = 0;
  timer2::onTick(&blink);
  timer2::start();
  sei();
  while (true)
  {
    led::write(value);
  }
  return 0;
}
