#include <Arduino.h>
#include "RelayControl.hpp"

RelayControl Relay_1(4, false);
RelayControl Relay_2(5, false);

void setup(void)
{
}

void loop(void)
{
  Relay_1.on();
  Relay_2.off();
  delay(741);
  Relay_1.off();
  Relay_2.on();
  delay(741);
}
