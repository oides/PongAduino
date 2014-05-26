/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#ifndef Pong_h
#define Pong_h

#include <LedControl.h>

#define DATA_IN 12
#define CLK 11
#define CS 10
#define NUMERO_MATRIZES 1

class Pong
{
  public:
    Pong();
    void start();
    void setMatrix(LedControl *ledMatrix);

  private:
    int _running;
    LedControl *_ledMatrix; 
};

#endif
