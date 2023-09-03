#include <uart.h>

int main()
{
  uart0::begin(9600);
  uart1::begin(9600);
  while (true)
  {
    if (uart0::available())
    {
        uart0::write(uart0::read());
    }
    if (uart1::available())
    {
        uart1::write(uart1::read());
    }
  }
  return 0;
}
