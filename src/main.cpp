#include <Arduino.h>
#include "RelayControl.hpp"

RelayControl Relay_1(4, false);
RelayControl Relay_2(5, false);

void setup(void)
{
}

void loop(void)
{
  Relay_1.relay_control(true);
  Relay_2.relay_control(false);
  delay(500);
  Relay_1.relay_control(false);
  Relay_2.relay_control(true);
}
