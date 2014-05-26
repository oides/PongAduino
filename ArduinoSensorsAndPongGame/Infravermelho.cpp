/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#include "Infravermelho.h"

void Infravermelho::loopApp()
{
  if (_running) _ledMatrix->printStringScroll(0, 0, "INFRA", 30, '<');
}
