/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#ifndef Pong_h
#define Pong_h

#include <LedControl.h>
#include "BaseApp.h"

class Pong: public BaseApp
{
  public:
    void startApp();
    void stopApp();  
    void loopApp();
};

#endif
