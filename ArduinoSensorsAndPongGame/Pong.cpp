/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#include "Pong.h"
#include <binary.h>

void Pong::loopApp()
{
  if (_running)
  {
    _ledMatrix->setRow(0,2,B10110000);
    delay(1000);
    _ledMatrix->printStringScroll(0, 0, "PONG", 30, '<');
  }
}

void Pong::startApp()
{  
  BaseClass:startApp();
}

void Pong::stopApp()
{
  BaseClass:stopApp();
}
