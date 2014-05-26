/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#include "Pong.h"

void Pong::loopApp()
{
  if (_running) _ledMatrix->printStringScroll(0, 0, "PONG", 30, '<');
}
