/*
Transmitter Code for TX


Potentiometer Setup
   ____________
  |  --------  |
  |  |      |  |---
  |  |      |  |--- Y
  |  --------  |---
  |____________|
      |  |  |
        X
*/

#include <printf.h>
#include <nRF24L01.h>
#include <RF24_config.h>
#include <RF24.h>
#include <SPI.h>

//pot values for direction -- pls dont forget to append after #define
#define center 512
#define up 1023
#define down 0
#define left 1023
#define right 0
 
#define CE_PIN   14
#define CSN_PIN 15

const int leftPotX = 16; //A2
const int leftPotY = 17; //A3

const int rightPotX = 18; //A4
const int rightPotY = 19; //A5

const byte address[6] = "00001";

RF24 radio(CE_PIN, CSN_PIN);

char command;

void sendCommand()
{
  radio.write(&command, sizeof(command));
}

int readLeftPotX()
{
  return analogRead(leftPotX);
}

int readLeftPotY()
{
  return analogRead(leftPotY);
}

int readRightPotX()
{
  return analogRead(rightPotX);
}

int readRightPotY()
{
  return analogRead(rightPotY);
}

void setup()
{
  pinMode(leftPotX, INPUT);
  pinMode(leftPotY, INPUT);
  pinMode(rightPotX, INPUT);
  pinMode(rightPotY, INPUT);

  radio.begin();
  radio.setPayloadSize(8);
  radio.setRetries(5, 15);
  radio.openWritingPipe(address);
}

void loop()
{
  if(readLeftPotX() || readLeftPotY() || readRightPotX() ||readRightPotY() == 512)
  {
    command = 'H';
  }
  //Left Potentiometer Commands 
  if(readLeftPotX() == left)
  {
    command = 'RL';
  } 
  if(readLeftPotX() == right)
  {
    command = 'RR';
  }
  if(readLeftPotY() == up)
  {
    command = 'RF';
  }
    if(readLeftPotY() == down)
  {
    command = 'RB';
  }

  //Right Potentiometer Commands
  if(readRightPotX() == left)
  {
    command = 'YL';
  }
    if(readRightPotX() == right)
  {
    command = 'YR';
  }  
  if(readRightPotY() == up)
  {
    command = 'U';
  }  
  if(readRightPotY() == down)
  {
    command = 'D';
  }
  sendCommand();
}
