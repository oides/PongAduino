/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#ifndef Pong_h
#define Pong_h

#include <LedControl.h>
#include "BaseApp.h"
#include "GameModel.h"

class Pong: public BaseApp
{
  public:
    void startApp();
    void stopApp();  
    void loopApp();
    void move(int side);

  private:
    void initializeGame();
    void loadScene();
    void drawPlayer();
    GameModel gameModel;
};

#endif
