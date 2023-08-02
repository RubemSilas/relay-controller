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

void RelayControl::on(void)
{
    pin_state = _ref_status;
    digitalWrite(_pin, pin_state);
}

void RelayControl::off(void)
{
    pin_state = !_ref_status;
    digitalWrite(_pin, pin_state);
}

void RelayControl::toggle(void)
{
    pin_state = !pin_state;
    digitalWrite(_pin, !_ref_status);
}
