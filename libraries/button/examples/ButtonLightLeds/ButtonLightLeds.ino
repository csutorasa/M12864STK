#include <button.h>
#include <led.h>

int main() {
  led::initialize();
  button::initialize();
  while(true)
  {
    uint8_t read = button::read();
    led::write(read);
  }
  return 0;
}
