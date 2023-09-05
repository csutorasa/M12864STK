#ifndef M12864STK_INTERRUPT_H
#define M12864STK_INTERRUPT_H

#include <stdint.h>

typedef void (*InterruptAction)();

namespace interrupt0
{
  /**
   * Initializes the interrupt.
   */
  void initialize();
  /**
   * Sets the event of the timer.
   * @param event Event to be called after the timer overflows
   */
  void onInterrupt(InterruptAction event);
}

namespace interrupt1
{
  /**
   * Initializes the interrupt.
   */
  void initialize();
  /**
   * Sets the event of the timer.
   * @param event Event to be called after the timer overflows
   */
  void onInterrupt(InterruptAction event);
}

namespace interrupt2
{
  /**
   * Initializes the interrupt.
   */
  void initialize();
  /**
   * Sets the event of the timer.
   * @param event Event to be called after the timer overflows
   */
  void onInterrupt(InterruptAction event);
}

namespace interrupt3
{
  /**
   * Initializes the interrupt.
   */
  void initialize();
  /**
   * Sets the event of the timer.
   * @param event Event to be called after the timer overflows
   */
  void onInterrupt(InterruptAction event);
}

namespace interrupt4
{
  /**
   * Initializes the interrupt.
   */
  void initialize();
  /**
   * Sets the event of the timer.
   * @param event Event to be called after the timer overflows
   */
  void onInterrupt(InterruptAction event);
}

namespace interrupt5
{
  /**
   * Initializes the interrupt.
   */
  void initialize();
  /**
   * Sets the event of the timer.
   * @param event Event to be called after the timer overflows
   */
  void onInterrupt(InterruptAction event);
}

namespace interrupt6
{
  /**
   * Initializes the interrupt.
   */
  void initialize();
  /**
   * Sets the event of the timer.
   * @param event Event to be called after the timer overflows
   */
  void onInterrupt(InterruptAction event);
}

namespace interrupt7
{
  /**
   * Initializes the interrupt.
   */
  void initialize();
  /**
   * Sets the event of the timer.
   * @param event Event to be called after the timer overflows
   */
  void onInterrupt(InterruptAction event);
}

#endif