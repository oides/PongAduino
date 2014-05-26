/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#ifndef Infravermelho_h
#define Infravermelho_h

#include <LedControl.h>
#include "BaseApp.h"

class Infravermelho: public BaseApp
{
  public:
    void loopApp();
};

#endif
