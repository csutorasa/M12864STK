#include <display.h>

int main() {
  display::initialize();
  display::print("test");
  while (true)
  {
    display::refresh();
  }
  return 0;
}
