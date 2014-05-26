/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#include "Temperatura.h"

void Temperatura::loopApp()
{
  if (_running) _ledMatrix->printStringScroll(0, 0, "TEMP", 30, '<');
}
