#include "interrupt.h"

#include <Arduino.h>

void noOpAction() { }

namespace interrupt0
{
  namespace
  {
    InterruptAction event = &noOpAction;
  }

  void initialize()
  {
    DDRD &= ~(1 << INT0);
    PORTD |= 1 << INT0;
    EICRA |= 1 << ISC01;
    EIMSK |= 1 << INT0;
  }

  void onInterrupt(InterruptAction ev)
  {
    event = ev;
  }

  void stop()
  {
    EIMSK &= ~(1 << INT0);
  }

  void tick()
  {
    event();
  }
}

ISR(INT0_vect)
{
  interrupt0::tick();
}

namespace interrupt1
{
  namespace
  {
    InterruptAction event = &noOpAction;
  }

  void initialize()
  {
    DDRD &= ~(1 << INT1);
    PORTD |= 1 << INT1;
    EICRA |= 1 << ISC11;
    EIMSK |= 1 << INT1;
  }

  void onInterrupt(InterruptAction ev)
  {
    event = ev;
  }

  void stop()
  {
    EIMSK &= ~(1 << INT1);
  }

  void tick()
  {
    event();
  }
}

ISR(INT1_vect)
{
  interrupt1::tick();
}

namespace interrupt2
{
  namespace
  {
    InterruptAction event = &noOpAction;
  }

  void initialize()
  {
    DDRD &= ~(1 << INT2);
    PORTD |= 1 << INT2;
    EICRA |= 1 << ISC21;
    EIMSK |= 1 << INT2;
  }

  void onInterrupt(InterruptAction ev)
  {
    event = ev;
  }

  void stop()
  {
    EIMSK &= ~(1 << INT2);
  }

  void tick()
  {
    event();
  }
}

ISR(INT2_vect)
{
  interrupt2::tick();
}

namespace interrupt3
{
  namespace
  {
    InterruptAction event = &noOpAction;
  }

  void initialize()
  {
    DDRD &= ~(1 << INT3);
    PORTD |= 1 << INT3;
    EICRA |= 1 << ISC31;
    EIMSK |= 1 << INT3;
  }

  void onInterrupt(InterruptAction ev)
  {
    event = ev;
  }

  void stop()
  {
    EIMSK &= ~(1 << INT3);
  }

  void tick()
  {
    event();
  }
}

ISR(INT3_vect)
{
  interrupt3::tick();
}

namespace interrupt4
{
  namespace
  {
    InterruptAction event = &noOpAction;
  }

  void initialize()
  {
    DDRD &= ~(1 << INT4);
    PORTD |= 1 << INT4;
    EICRB |= 1 << ISC41;
    EIMSK |= 1 << INT4;
  }

  void onInterrupt(InterruptAction ev)
  {
    event = ev;
  }

  void stop()
  {
    EIMSK &= ~(1 << INT4);
  }

  void tick()
  {
    event();
  }
}

ISR(INT4_vect)
{
  interrupt4::tick();
}

namespace interrupt5
{
  namespace
  {
    InterruptAction event = &noOpAction;
  }

  void initialize()
  {
    DDRD &= ~(1 << INT5);
    PORTD |= 1 << INT5;
    EICRB |= 1 << ISC51;
    EIMSK |= 1 << INT5;
  }

  void onInterrupt(InterruptAction ev)
  {
    event = ev;
  }

  void stop()
  {
    EIMSK &= ~(1 << INT5);
  }

  void tick()
  {
    event();
  }
}

ISR(INT5_vect)
{
  interrupt5::tick();
}

namespace interrupt6
{
  namespace
  {
    InterruptAction event = &noOpAction;
  }

  void initialize()
  {
    DDRD &= ~(1 << INT6);
    PORTD |= 1 << INT6;
    EICRB |= 1 << ISC61;
    EIMSK |= 1 << INT6;
  }

  void onInterrupt(InterruptAction ev)
  {
    event = ev;
  }

  void stop()
  {
    EIMSK &= ~(1 << INT6);
  }

  void tick()
  {
    event();
  }
}

ISR(INT6_vect)
{
  interrupt6::tick();
}

namespace interrupt7
{
  namespace
  {
    InterruptAction event = &noOpAction;
  }

  void initialize()
  {
    DDRD &= ~(1 << INT7);
    PORTD |= 1 << INT7;
    EICRA |= 1 << ISC71;
    EIMSK |= 1 << INT7;
  }

  void onInterrupt(InterruptAction ev)
  {
    event = ev;
  }

  void stop()
  {
    EIMSK &= ~(1 << INT7);
  }

  void tick()
  {
    event();
  }
}

ISR(INT7_vect)
{
  interrupt7::tick();
}