#ifndef M12864STK_TIMER_H
#define M12864STK_TIMER_H

#include <stdint.h>

typedef void (*TimerAction)();

namespace timer0
{
  /**
   * Starts the timer.
   */
  void start();
  /**
   * Starts the timer.
   * @param limit The Counter overflow value.
   */
  void start(uint8_t limit);
  /**
   * Sets the event of the timer.
   * @param event Event to be called after the timer overflows
   */
  void onTick(TimerAction event);
  /**
   * Stops the timer.
   */
  void stop();
}

namespace timer1
{
  /**
   * Starts the timer.
   */
  void start();
  /**
   * Starts the timer.
   * @param limit The Counter overflow value.
   */
  void start(uint16_t limit);
  /**
   * Sets the event of the timer.
   * @param event Event to be called after the timer overflows
   */
  void onTick(TimerAction event);
  /**
   * Stops the timer.
   */
  void stop();
}

namespace timer2
{
  /**
   * Starts the timer.
   */
  void start();
  /**
   * Starts the timer.
   * @param limit The Counter overflow value.
   */
  void start(uint8_t limit);
  /**
   * Sets the event of the timer.
   * @param event Event to be called after the timer overflows
   */
  void onTick(TimerAction event);
  /**
   * Stops the timer.
   */
  void stop();
}

#endif