#include "uart.h"

#include <M12864stk.h>

uint16_t calculateRate(uint16_t baud) {
  return F_CPU / 16 / baud - 1;
}

namespace uart0
{
  void begin(uint16_t baud)
  {
    uint16_t ubbr = calculateRate(baud);
    UBRR0H = (uint8_t)(ubbr >> 8);
    UBRR0L = (uint8_t)ubbr;
    UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  }

  void write(uint8_t data)
  {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
  }

  uint8_t available()
  {
    return UCSR0A & (1 << RXC0);
  }

  uint8_t read()
  {
    while (!available());
    return UDR0;
  }
}

namespace uart1
{
  void begin(uint16_t baud)
  {
    uint16_t ubbr = calculateRate(baud);
    UBRR1H = (uint8_t)(ubbr >> 8);
    UBRR1L = (uint8_t)ubbr;
    UCSR1C = (1 << UCSZ10) | (1 << UCSZ11);
    UCSR1B = (1 << RXEN1) | (1 << TXEN1);
  }

  void write(uint8_t data)
  {
    while (!(UCSR1A & (1 << UDRE1)));
    UDR1 = data;
  }

  uint8_t available()
  {
    return UCSR1A & (1 << RXC1);
  }

  uint8_t read()
  {
    while (!available());
    return UDR1;
  }
}
