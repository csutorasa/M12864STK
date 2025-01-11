#ifndef M12864STK_UART_H
#define M12864STK_UART_H

#include <stdint.h>

/**
 * The panel has 2 UART Registers connected to the ATmega128A.
 */
namespace uart0 {    
  /**
   * Starts UART communication, and enables two way commonication.
   * @param baud baud rate
   */
  void begin(uint16_t baud);
  /**
   * Writes a byte to UART.
   * @param data Byte to write
   */
  void write(uint8_t data);
  /**
   * Reads a byte from UART.
   * @return read value
   */
  uint8_t read();
  /**
   * Checks if UART has available data to read.
   * @return non 0 if data is available
   */
  uint8_t available();
}

namespace uart1 {    
  /**
   * Starts UART communication, and enables two way commonication.
   * @param baud baud rate
   */
  void begin(uint16_t baud);
  /**
   * Writes a byte to UART.
   * @param data Byte to write
   */
  void write(uint8_t data);
  /**
   * Reads a byte from UART.
   * @return read value
   */
  uint8_t read();
  /**
   * Checks if UART has available data to read.
   * @return non 0 if data is available
   */
  uint8_t available();
} 

#endif
