/*

  Controlador adaptado do conteudo do curso: C++, Curso Completo - WR Kits

*/

#ifndef RELAYCONTROL_HPP
#define RELAYCONTROL_HPP

#include <stdlib.h>
#include <stdint.h>

class RelayControl
{
public:
  RelayControl(const uint16_t pin, const bool ref_status);

  void relay_control(const bool pin_state);
  void on(void);
  void off(void);
  void toggle(void);
  void pulse_timer(uint16_t pulse_timer_interval = 500);

  void setTime(unsigned msTime);
  uint16_t getTime(void) const;

private:
  const uint16_t _pin;
  const bool _ref_status;
  uint16_t _msTime;
  bool pin_state;
};

#endif
