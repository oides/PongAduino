/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#include "Pong.h"
#include <binary.h>
#include <XBeeJoystick.h>

void Pong::loopApp()
{
  if (_running)
  {
    loadScene();
    drawPlayer();
  }
}

void Pong::startApp()
{  
  BaseApp::startApp();
  initializeGame();
}

void Pong::stopApp()
{
  BaseApp::stopApp();
}

void Pong::initializeGame()
{
  gameModel.playerPosition = 3;
}

void Pong::loadScene()
{
  _ledMatrix->setRow(0,0,B11111111);
  _ledMatrix->setRow(0,1,B00000001);
  _ledMatrix->setRow(0,2,B00000001);
  _ledMatrix->setRow(0,3,B00000001);
  _ledMatrix->setRow(0,4,B00000001);
  _ledMatrix->setRow(0,5,B00000001);
  _ledMatrix->setRow(0,6,B00000001);
  _ledMatrix->setRow(0,7,B11111111);
}

void Pong::drawPlayer()
{
  _ledMatrix->setRow(0, gameModel.playerPosition, B10000000);
  _ledMatrix->setRow(0, gameModel.playerPosition + 1, B10000000);
}

void Pong::move(int side)
{
  if (BUTTON_LEFT == side && gameModel.playerPosition > 1) {
    gameModel.playerPosition -= 1;
  }
  if (BUTTON_RIGHT == side  && gameModel.playerPosition < 5) {
    gameModel.playerPosition += 1;
  }
}
