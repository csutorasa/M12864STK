#include "timer.h"

#include <M12864stk.h>

void noOpAction() { }

namespace timer0
{
  namespace
  {
    TimerAction event = &noOpAction;
  }

  void start(uint8_t limit)
  {
    OCR0 = limit;
    TCCR0 |= 0b110 << CS00; // 256 prescale
    TIMSK |= 1 << OCIE0; // enable 
    //TIFR |= 0b11 << TOV0; // enable 
    TCNT0 = 0;
  }

  void start()
  {
    TCCR0 |= 0b110 << CS00; // 256 prescale
    TIMSK |= 1 << TOIE0; // enable 
    //TIFR |= 0b11 << TOV0; // enable 
    TCNT0 = 0;
  }

  void onTick(TimerAction ev)
  {
    event = ev;
  }

  void stop()
  {
    TIMSK &= 0b11111100;
    TIFR &= 0b11111100;
  }

  void tick()
  {
    event();
  }
}

ISR(TIMER0_COMP_vect)
{
  timer0::tick();
  TCNT0 = 0;
}

ISR(TIMER0_OVF_vect)
{
  timer0::tick();
  TCNT0 = 0;
}

namespace timer1
{
  namespace
  {
    TimerAction event = &noOpAction;
  }

  void start(uint16_t limit)
  {
    //OCR1 = limit;
    TCCR0 |= 0b100 << CS10; // 256 prescale
    // TODO enable
    TCNT1 = 0;
  }

  void onTick(TimerAction ev)
  {
    event = ev;
  }

  void stop()
  {
    TIMSK &= 0b11000011;
    TIFR &= 0b11000011;
  }

  void tick()
  {
    event();
  }
}

ISR(TIMER1_COMP_vect)
{
  timer1::tick();
  TCNT1 = 0;
}

ISR(TIMER1_OVF_vect)
{
  timer1::tick();
  TCNT1 = 0;
}

namespace timer2
{
  namespace
  {
    TimerAction event = &noOpAction;
  }

  void start(uint8_t limit)
  {
    OCR2 = limit;
    TCCR2 = 0;
    TCCR2 |= 0b110 << CS20; // 256 prescale
    TCCR2 |= 1 << COM21; 
    TIMSK |= 1 << OCIE2; // enable 
    TCNT2 = 200;
  }

  void start()
  {
    TCCR2 = 0;
    TCCR2 |= 0b100 << CS20; // 256 prescale
    TCCR2 |= 1 << COM21; 
    TIMSK |= 1 << TOIE2; // enable 
    TCNT2 = 0;
  }

  void onTick(TimerAction ev)
  {
    event = ev;
  }

  void stop()
  {
    TIMSK &= 0b00111111;
    TIFR &= 0b00111111;
  }

  void tick()
  {
    event();
  }
}

ISR(TIMER2_COMP_vect)
{
  timer2::tick();
  TCNT2 = 0;
}

ISR(TIMER2_OVF_vect)
{
  timer2::tick();
  TCNT2 = 0;
}
