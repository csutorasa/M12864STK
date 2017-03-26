#include "m12864stk.h"

void UART::begin(uint16_t baud)
{
  uint16_t ubbr = F_CPU / 16 / baud - 1;
  UBRR1H = (uint8_t)(ubbr >> 8);
  UBRR1L = (uint8_t)ubbr;
  UCSR1B = (1 << RXEN1) | (1 << TXEN1);
  UCSR1C = (1 << UCSZ10) | (1 << UCSZ11);
}

void UART::print(uint8_t data)
{
  while (!(UCSR1A & (1 << UDRE1)));
  UDR1 = data;
}

uint8_t UART::available()
{
  return UCSR1A & (1 << RXC1);
}

uint8_t UART::read()
{
  while (!available());
  return UDR1;
}

Button::Button()
{
  DDRB = 0x00;
  PORTB = 0xff;
}

uint8_t Button::get(uint8_t pin)
{
  return !bitRead(PINB, pin);
}

uint8_t Button::read() {
  return PINB ^ 0xff;
}

LED::LED()
{
  DDRC = 0xff;
  PORTC = 0xff;
}

void LED::clear(uint8_t pin)
{
  bitSet(PORTC, pin);
}

void LED::set(uint8_t pin)
{
  bitClear(PORTC, pin);
}

void LED::write(uint8_t value)
{
  PORTC = value ^ 0xff;
}

void LED::write(uint8_t pin, uint8_t value)
{
  bitWrite(PORTC, pin, !value);
}

uint8_t LED::read()
{
  return PORTC ^ 0xff;
}

uint8_t LED::read(uint8_t pin)
{
  return !bitRead(PORTC, pin);
}

Display::Display()
{
  DDRA = 0xff;
  PORTA = 0x00;
  current = 0;
}

void Display::print(String str)
{
  if(str.length() != 8)
  {
    if(str.length() < 8)
    {
      for(int i = str.length(); i < 8; i++)
      {
        str = String(" ") + str;
      }
    }
    else
    {
      str.remove(8);
    }
  }
  print(str.charAt(0), 7);
  print(str.charAt(1), 6);
  print(str.charAt(2), 5);
  print(str.charAt(3), 4);
  print(str.charAt(4), 3);
  print(str.charAt(5), 2);
  print(str.charAt(6), 1);
  print(str.charAt(7), 0);
}

void Display::print(char ch, uint8_t pos)
{
  if('0' <= ch && ch <= '9')
  {
    data[pos] = numbers[ch - '0'];
    return;
  }
  if('A' <= ch && ch <= 'Z')
  {
    data[pos] = letters[ch - 'A'];
    return;
  }
  if('a' <= ch && ch <= 'z')
  {
    data[pos] = letters[ch - 'a'];
    return;
  }
  data[pos] = 0xff;
}

void Display::refresh()
{
  bitClear(PORTA, 4);
  bitWrite(PORTA, 5, bitRead(current, 2));
  bitWrite(PORTA, 6, bitRead(current, 1));
  bitWrite(PORTA, 7, bitRead(current, 0));
  
  for(uint8_t i = 0; i < 8; i++)
  {
    bitWrite(PORTA, 3, bitRead(data[current], i));
    bitSet(PORTA, 1);
    bitClear(PORTA, 1);
  }
  bitSet(PORTA, 2);
  bitClear(PORTA, 2);
  
  bitSet(PORTA, 4);

  if(current == 7)
    current = 0;
  else
    current++;
}

Buzzer::Buzzer()
{
  bitSet(DDRG, 3);
  bitClear(PORTG, 3);
}

void Buzzer::set()
{
  bitSet(PORTG, 3);
}

void Buzzer::clear()
{
  bitSet(PORTG, 3);
}

void Timer0::start(uint8_t limit)
{
  OCR0 = limit;
  TCCR0 = 0b00000110; // 256 prescale
  TCCR0 |= 0b10 << COM00;
  TCCR0 |= 1 << WGM01;
  TIMSK |= 0b11 << TOIE0; // enable 
  TIFR |= 0b11 << TOV0; // enable 
  TCNT0 = 0;
}

void Timer0::onTick(void (*event)())
{
  this->event = event;
}

void Timer0::tick()
{
  event();
}

void Timer0::stop()
{
  TIMSK &= 0b11111100;
  TIFR &= 0b11111100;
}

Timer0 timer0;

ISR(TIMER0_COMP_vect)
{
  timer0.tick();
  TCNT0 = 0;
}
Button button;
UART uart;
LED led;
Display display;
Buzzer buzzer;
