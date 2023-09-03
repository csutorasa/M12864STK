#include <led.h>

int main() {
  led::initialize();
  led::write(0xff);
  return 0;
}
