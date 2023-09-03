#include "display.h"

#include <Arduino.h>

namespace display
{
  namespace
  {
    uint8_t data[8] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    const uint8_t numbers[10] = {
      0b00000011, // 0
      0b10011111, // 1
      0b00100101, // 2
      0b00001101, // 3
      0b10011001, // 4
      0b01001001, // 5
      0b01000001, // 6
      0b00011111, // 7
      0b00000001, // 8
      0b00001001 // 9
    };
    const uint8_t letters[26] = {
      0b00010001, // A
      0b11000001, // B
      0b01100011, // C
      0b10000101, // D
      0b01100001, // E
      0b01110001, // F
      0b01000011, // G
      0b11010001, // H
      0b11110011, // I
      0b10001111, // J
      0b10010001, // K
      0b11100011, // L
      0b00010011, // M
      0b11010101, // N
      0b11000101, // O
      0b00110001, // P
      0b00011001, // Q
      0b11110101, // R
      0b01001001, // S
      0b11100001, // T
      0b10000011, // U
      0b11000111, // V
      0b01000111, // W
      0b10010001, // X
      0b10001001, // Y
      0b00100101 // Z
    };
  }

  void initialize()
  {
    DDRA = 0xff;
    PORTA = 0x00;
  }

  void print(const char* str)
  {
    size_t len = strlen(str);
    for (size_t i = 0; i < 8; i++)
    {
      if (i < len)
      {
        print(str[i], 7 - i);
      }
      else 
      {
        print(str[i], 7 - i);
      }
    }
  }

  uint8_t getMask(char ch)
  {
    if('0' <= ch && ch <= '9')
    {
      return numbers[ch - '0'];
    }
    if('A' <= ch && ch <= 'Z')
    {
      return letters[ch - 'A'];
    }
    if('a' <= ch && ch <= 'z')
    {
      return letters[ch - 'a'];
    }
    return 0xff;
  }

  void print(char ch, uint8_t pos)
  {
    data[pos] = getMask(ch);
  }

  void refresh(uint8_t pos)
  {
    bitClear(PORTA, 4);
    // set digit index
    bitWrite(PORTA, 5, bitRead(pos, 2));
    bitWrite(PORTA, 6, bitRead(pos, 1));
    bitWrite(PORTA, 7, bitRead(pos, 0));
    
    for(uint8_t i = 0; i < 8; i++)
    {
      // Set digit value
      bitWrite(PORTA, 3, bitRead(data[pos], i));
      // Send interrupt
      bitSet(PORTA, 1);
      bitClear(PORTA, 1);
    }
    // Send interrupt
    bitSet(PORTA, 2);
    bitClear(PORTA, 2);
    
    bitSet(PORTA, 4);
  }

  void refresh()
  {
    for(uint8_t i = 0; i < 8; i++)
    {
      refresh(i);
    }
  }
}
