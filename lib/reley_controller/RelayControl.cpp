#include "RelayControl.hpp"
#include <Arduino.h>

RelayControl::RelayControl(const uint16_t pin, const bool ref_status) : _pin(pin), _ref_status(ref_status), _msTime(500)
{
    pinMode(_pin, OUTPUT);
}

void RelayControl::relay_control(const bool pin_state)
{
    bool curr_state;

    curr_state = pin_state ^ (!_ref_status);
    this->pin_state = curr_state;
    digitalWrite(_pin, curr_state); 
}