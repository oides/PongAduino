/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#include "Luz.h"

const int sensor = 0;
char valorSensor[4];

void Luz::loopApp()
{
  if (_running)
  {
    _ledMatrix->printStringScroll(0, 0, "Ilulinacao: ", MESSAGE_SPEED, '<');
    
    dtostrf(analogRead(sensor), 2, 0, valorSensor);
    _ledMatrix->printStringScroll(0, 0, valorSensor, MESSAGE_SPEED, '<');
    
    delay(1000);
  }
}
