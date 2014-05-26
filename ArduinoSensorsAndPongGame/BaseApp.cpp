/*
  XBeeJoystick.h - Library for XBeeJoystick arduino code.
  Coded by Oidas Andrade.
*/
#include "BaseApp.h"

void BaseApp::setupApp(String appName, LedControl *ledMatrix)
{
  _ledMatrix = ledMatrix;
  _appName = appName;
  
  _running = false;  
}

void BaseApp::startApp()
{  
  if (!_running)
  {
    String message = "Iniciando ";
    message += _appName;  
  
    char startMessage[message.length() + 1];
    message.toCharArray(startMessage, message.length() + 1);
  
    _ledMatrix->printStringScroll(0, 0, startMessage , 60, '<');
    _running = true;
  }
}

void BaseApp::stopApp()
{
  if (_running)
  {
    String message = "Parando ";
    message += _appName;  
  
    char stopMessage[message.length() + 1];
    message.toCharArray(stopMessage, message.length() + 1);
  
    _ledMatrix->printStringScroll(0, 0, stopMessage , 60, '<');
    _running = false;
  }
}


