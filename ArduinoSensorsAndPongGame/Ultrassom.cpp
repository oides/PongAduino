/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#include "Ultrassom.h"

void Ultrassom::loopApp()
{
  if (_running) _ledMatrix->printStringScroll(0, 0, "ULTRA", 30, '<');
}
