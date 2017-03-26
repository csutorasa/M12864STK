#include<m12864stk.h>

void setup() {
  // put your setup code here, to run once:
  uart.begin(9600);
  display.print("Test App");
}

void loop() {
  // put your main code here, to run repeatedly:
  byte values = button.read();
  led.write(values);
  display.refresh();
  if(uart.available()) {
    uart.print(uart.read());
  }
}




