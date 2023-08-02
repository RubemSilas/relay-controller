#include <Arduino.h>
#include "RelayControl.hpp"

RelayControl Relay_1(4, false);

void pin_set(const uint16_t pin, const bool pin_state);
void wait(const uint16_t interval_time);

void setup(void)
{
  Relay_1.pin_set_callback(&pin_set);
  Relay_1.wait_callback(&wait);
}

void loop(void)
{
  Relay_1.pulse_timer(2 * 1000);
  delay(500);
}

void pin_set(const uint16_t pin, const bool pin_state)
{
  digitalWrite(pin, pin_state);
}

void wait(const uint16_t interval_time)
{
  delay(interval_time);
}