#include <button.h>
#include <buzzer.h>

int main() {
  led::initialize();
  buzzer::initialize();
  while(true)
  {
    uint8_t read = button::read(0);
    if (read)
    {
        buzzer::set();
    }
    else
    {
        buzzer::clear();
    }
  }
  return 0;
}
