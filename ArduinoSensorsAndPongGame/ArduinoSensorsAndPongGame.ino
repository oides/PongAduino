#include <XBeeJoystick.h>
#include <XBee.h>
#include <LedControl.h>
#include "Pong.h"

#define DATA_IN 12
#define CLK 11
#define CS 10
#define NUMERO_MATRIZES 1


XBeeJoystick xBeeJoystick;
LedControl ledMatrix = LedControl(DATA_IN, CLK, CS, NUMERO_MATRIZES); 
Pong pong;

void setup()
{   
  Serial.begin(9600);  
  setupMatrix();  
  pong.setMatrix(&ledMatrix);
}

void loop()
{  
  int joystickButtonPressed = xBeeJoystick.readJoystick();
  
  if (joystickButtonPressed)
  {
    if (joystickButtonPressed == BUTTON_A)
    {        
      loadUltrassomApp();      
    }      
    if (joystickButtonPressed == BUTTON_B)
    {
      loadTemperaturaApp();      
    }
    if (joystickButtonPressed == BUTTON_C)
    {
      loadLuzApp();      
    }
    if (joystickButtonPressed == BUTTON_D)
    {
      loadInfravermelhoApp();      
    }    
    if (joystickButtonPressed == BUTTON_LEFT || joystickButtonPressed == BUTTON_RIGHT)
    {
      loadPongApp(joystickButtonPressed);
    }    
  }

}

void loadUltrassomApp()
{
  ledMatrix.printStringScroll(0, 0, "Iniciando ultrassom", 50, '<');
}

void loadTemperaturaApp()
{
  ledMatrix.printStringScroll(0, 0, "Iniciando temperatura", 50, '<');
}

void loadLuzApp()
{
  ledMatrix.printStringScroll(0, 0, "Iniciando Luz", 50, '<');
}

void loadInfravermelhoApp()
{
  ledMatrix.printStringScroll(0, 0, "Iniciando infravermelho", 50, '<');
}

void loadPongApp(int buttonPressed)
{
  pong.start();
}

void setupMatrix()
{
  ledMatrix.shutdown(0, false);
  ledMatrix.setIntensity(0, 0);
  ledMatrix.clearDisplay(0);
  
  ledMatrix.printStringScroll(0, 0, "Trabalho Final INF611", 50, '<');
}
