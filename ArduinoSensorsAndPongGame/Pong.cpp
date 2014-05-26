/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#include "Pong.h"

Pong::Pong()
{
  _running = false;
}

void Pong::start()
{  
  _ledMatrix->printStringScroll(0, 0, "Iniciando Pong", 50, '<');
  _running = true;
}

void Pong::setMatrix(LedControl *ledMatrix)
{
  _ledMatrix = ledMatrix;
}
