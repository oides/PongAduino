/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#include "Luz.h"

void Luz::loopApp()
{
  if (_running) _ledMatrix->printStringScroll(0, 0, "LUZ", 30, '<');
}
