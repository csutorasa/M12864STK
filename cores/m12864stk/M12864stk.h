#ifndef M12864STK
#define M12864STK

#include <Arduino.h>

/**
 * ATmega128a is operating at 8 MHz.
 */
#define F_CPU 8000000L

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

#endif // M12864STK