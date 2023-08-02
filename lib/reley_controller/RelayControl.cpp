#include "RelayControl.hpp"
#include <Arduino.h>

RelayControl::RelayControl(const uint16_t pin, const bool ref_status) : _pin(pin), _ref_status(ref_status), _msTime(500)
{
    pinMode(_pin, OUTPUT);
}

void RelayControl::pin_set_callback(pin_set_t callback)
{
    pin_out = callback;
    init_off();
}

void RelayControl::wait_callback(wait_t callback)
{
    waiting = callback;
}

void RelayControl::relay_control(const bool pin_state)
{
    bool curr_state;

    curr_state = pin_state ^ (!_ref_status);
    this->pin_state = curr_state;

    if (pin_out != NULL)
    {
        pin_out(_pin, curr_state);
    }
}

void RelayControl::on(void)
{
    pin_state = _ref_status;
    if (pin_out != NULL)
    {
        pin_out(_pin, _ref_status);
    }
}

void RelayControl::off(void)
{
    pin_state = !_ref_status;

    if (pin_out != NULL)
    {
        pin_out(_pin, !_ref_status);
    }
}

void RelayControl::toggle(void)
{
    pin_state = !pin_state;

    if (pin_out != NULL)
    {
        pin_out(_pin, pin_state);
    }
}

void RelayControl::pulse_timer(uint16_t pulse_timer_interval)
{
    _msTime = pulse_timer_interval;

    on();
    if (waiting != NULL)
    {
        waiting(_msTime);
    }
    off();
}

void RelayControl::setTime(unsigned msTime)
{
    _msTime = msTime;
}

uint16_t RelayControl::getTime(void) const
{
    return _msTime;
}

void RelayControl::init_off(void)
{
    if (pin_out != NULL)
    {
        pin_out(_pin, !_ref_status);
    }
}
