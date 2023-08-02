#include <Arduino.h>
#include "RelayControl.hpp"

RelayControl Relay_1(4, false);
RelayControl Relay_2(5, false);

void setup(void)
{
}

void loop(void)
{
  Relay_1.toggle();
  delay(741);
  Relay_1.pulse_timer(2 * 1000);
  Relay_2.pulse_timer(Relay_1.getTime());
  delay(500);
}
