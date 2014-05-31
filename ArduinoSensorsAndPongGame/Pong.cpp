/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#include "Pong.h"
#include "GameModel.h"
#include <binary.h>
#include <XBeeJoystick.h>
#include <TimerOne.h>

#define DEFAULT_GAME_SPEED 300000
#define TOPO_TELA 6
#define TELA_DIREITA 6
#define TELA_ESQUERDA 1
#define BASE_TELA 1

Pong *Pong::instance;

Pong::Pong()
{
  Pong::instance = this;
}

void Pong::loopApp()
{
  if (_running)
  {
    loadScene();
    drawPlayer();
    drawBall();
  }
}

void Pong::startApp()
{    
  initializeGame();
  BaseApp::startApp();
  
  Timer1.attachInterrupt(functionUpdateBallPosition);
}

void Pong::stopApp()
{
  BaseApp::stopApp();  
  Timer1.detachInterrupt();
}

void Pong::initializeGame()
{
  gameModel.playerPosition = 3;
  
  gameModel.ballPosition[0] = 3;
  gameModel.ballPosition[1] = 4;
  gameModel.ballAngle = BALL_UP;
  
  Timer1.initialize(DEFAULT_GAME_SPEED);
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

void Pong::drawBall()
{
  _ledMatrix->setLed(0, gameModel.ballPosition[0], gameModel.ballPosition[1], true);
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

void Pong::updateBallPosition()
{
  // Eixo Y subindo
  if (ballBottomUp() && gameModel.ballPosition[1] < TOPO_TELA)
  {
    gameModel.ballPosition[1] += 1;
  }
  else if (ballBottomUp() && gameModel.ballPosition[1] == TOPO_TELA)
  {
    defineOpositeYTop();
    gameModel.ballPosition[1] -= 1;
  }
  // Eixo Y descendo
  else if (ballTopDown() && gameModel.ballPosition[1] > BASE_TELA)
  {
    gameModel.ballPosition[1] -= 1;
  }
  else if (ballTopDown() && gameModel.ballPosition[1] == BASE_TELA && ballMatchPlayer())
  {
    defineOpositeYPlayer();
    gameModel.ballPosition[1] += 1;
  }   
  else if (ballTopDown())
  {
    gameModel.ballPosition[1] -= 1;
  }   
  
  // Eixo X direita
  if (ballLeftRight() && gameModel.ballPosition[0] < TELA_DIREITA)
  {
    gameModel.ballPosition[0] += 1;
  }
  else if (ballLeftRight() && gameModel.ballPosition[0] == TELA_DIREITA)
  {
    defineOpositeX();
    gameModel.ballPosition[0] -= 1;
  }
  // Eixo X esquerda
  else if (ballRightLeft() && gameModel.ballPosition[0] > TELA_ESQUERDA)
  {
    gameModel.ballPosition[0] -= 1;
  }
  else if (ballRightLeft() && gameModel.ballPosition[0] == TELA_ESQUERDA)
  {
    defineOpositeX();
    gameModel.ballPosition[0] += 1;
  }  
  
}

boolean Pong::ballMatchPlayer()
{
  return ((gameModel.ballPosition[0] == gameModel.playerPosition) ||
          (gameModel.ballPosition[0] == gameModel.playerPosition + 1) ||
          (gameModel.ballAngle == BALL_DOWN_LEFT && gameModel.ballPosition[0] == gameModel.playerPosition + 2) ||
          (gameModel.ballAngle == BALL_DOWN_RIGHT && gameModel.ballPosition[0] == gameModel.playerPosition -1));
}

void Pong::defineOpositeX()
{
  if (gameModel.ballAngle == BALL_UP_RIGHT)
  {
    gameModel.ballAngle = BALL_UP_LEFT;
  }
  else if (gameModel.ballAngle == BALL_UP_LEFT)
  {
    gameModel.ballAngle = BALL_UP_RIGHT;
  }
  else if (gameModel.ballAngle == BALL_DOWN_RIGHT)
  {
    gameModel.ballAngle = BALL_DOWN_LEFT;
  }
  else if (gameModel.ballAngle == BALL_DOWN_LEFT)
  {
    gameModel.ballAngle = BALL_DOWN_RIGHT;
  }
}

void Pong::defineOpositeYTop()
{
  if (gameModel.ballAngle == BALL_UP)
  {
    gameModel.ballAngle = BALL_DOWN;
  }
  else if (gameModel.ballAngle == BALL_UP_RIGHT)
  {
    gameModel.ballAngle = BALL_DOWN_RIGHT;
  }
  else if (gameModel.ballAngle == BALL_UP_LEFT)
  {
    gameModel.ballAngle = BALL_DOWN_LEFT;
  }
}

void Pong::defineOpositeYPlayer()
{
  if (gameModel.ballAngle == BALL_DOWN && gameModel.ballPosition[0] == gameModel.playerPosition)
  {
    gameModel.ballAngle = BALL_UP_LEFT;
  }
  else if (gameModel.ballAngle == BALL_DOWN && gameModel.ballPosition[0] == gameModel.playerPosition + 1)
  {
    gameModel.ballAngle = BALL_UP_RIGHT;
  }
  else if (gameModel.ballAngle == BALL_DOWN_LEFT && gameModel.ballPosition[0] == gameModel.playerPosition)
  {
    gameModel.ballAngle = BALL_UP_LEFT;
  }
  else if (gameModel.ballAngle == BALL_DOWN_LEFT && gameModel.ballPosition[0] == gameModel.playerPosition + 1)
  {
    gameModel.ballAngle = BALL_UP;
  }
  else if (gameModel.ballAngle == BALL_DOWN_LEFT && gameModel.ballPosition[0] == gameModel.playerPosition + 2)
  {
    gameModel.ballAngle = BALL_UP_RIGHT;
  }
  else if (gameModel.ballAngle == BALL_DOWN_RIGHT && gameModel.ballPosition[0] == gameModel.playerPosition - 1)
  {
    gameModel.ballAngle = BALL_UP_LEFT;
  }
  else if (gameModel.ballAngle == BALL_DOWN_RIGHT && gameModel.ballPosition[0] == gameModel.playerPosition)
  {
    gameModel.ballAngle = BALL_UP;
  }
  else if (gameModel.ballAngle == BALL_DOWN_RIGHT && gameModel.ballPosition[0] == gameModel.playerPosition + 1)
  {
    gameModel.ballAngle = BALL_UP_RIGHT;
  }
}

boolean Pong::ballLeftRight()
{
  return (gameModel.ballAngle == BALL_UP_RIGHT || gameModel.ballAngle == BALL_DOWN_RIGHT);
}

boolean Pong::ballRightLeft()
{
  return (gameModel.ballAngle == BALL_UP_LEFT || gameModel.ballAngle == BALL_DOWN_LEFT);
}

boolean Pong::ballBottomUp()
{
  return (gameModel.ballAngle == BALL_UP || gameModel.ballAngle == BALL_UP_RIGHT || gameModel.ballAngle == BALL_UP_LEFT);
}

boolean Pong::ballTopDown()
{
  return (gameModel.ballAngle == BALL_DOWN || gameModel.ballAngle == BALL_DOWN_RIGHT || gameModel.ballAngle == BALL_DOWN_LEFT);
}

void functionUpdateBallPosition()
{
  Pong::instance->updateBallPosition();
}
