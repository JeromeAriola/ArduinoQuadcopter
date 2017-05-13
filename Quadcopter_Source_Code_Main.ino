/*
Receiver Code(RX)/Quadcopter Side
The setup for the quad is:
  -4 brushless motors (RacerStar BR 2212) rated at 25A
  -4 propellers(duh! GemFan 6040)
  -4 ESCs (HW30A XXD)
  -Power Distribution Board (not required, but recommended)
  -4000mAh 45C 3S Lipo (XF Power)
  -Arduino Nano(remember this is Rx so of course there is a second Arduino)
  -NRF24L01+ PA LNA (same as previous part, this is Rx)
  
Pins 5 and 6 are the back motors, while pins 9 and 10 are the front motors. How I can find my sense
of direction is that the front left motor rotates CCW.

The motor setup and how it's attached to the Arduino
   _________________
  |  pin 9 | pin 10 |
  |  CCW   |  CW    |
  |        |        |
  -------------------
  | pin 5  |  pin 6 |
  |  CW    |   CCW  |
  |________|________|

*/

#include <nRF24L01.h>
#include <RF24.h>

#include <SPI.h>
#include <Servo.h>

Servo backLeft;
Servo backRight;
Servo frontLeft;
Servo frontRight;

#define CE_PIN 14     //A0 pin
#define CSN_PIN 15    //A1 pin

char command;

const byte address[6] ="00001" ;    //this simply specifies the 'address' that I will be using

RF24 radio(CE_PIN, CSN_PIN);

void setup()
{
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPayloadSize(8);
  radio.openReadingPipe(0, 00001);
  radio.setRetries(15, 15);
  radio.startListening();

  
  backLeft.attach(5);
  backRight.attach(6);
  frontLeft.attach(9);
  frontRight.attach(10);
  
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

//Movement Functions --not tested with drone; full of assumptions

void hover()
{
  backLeft.write(90);           //this simply assumes that half speed is like half
  backRight.write(90);          //turn in a servo
  frontLeft.write(90);
  frontRight.write(90);
}

void altitudeUp()
{
  backLeft.write(170);
  backRight.write(170);     //a little almost full speed or full turn in
  frontLeft.write(170);     //servo. 180 is a burst speed for the ESCs
  frontRight.write(170);
}

void altitudeDown()
{
  backLeft.write(60);
  backRight.write(60);
  frontLeft.write(60);
  frontRight.write(60);
}

void rollLeft()
{
  backLeft.write(60);
  backRight.write(135);
  frontLeft.write(60);
  frontRight.write(135);
}

void rollRight()
{
  backLeft.write(135);
  backRight.write(60);
  frontLeft.write(135);
  frontRight.write(60);
}

void rollFront()
{
  backLeft.write(135);
  backRight.write(135);
  frontLeft.write(60);
  frontRight.write(60);
}

void rollBack()
{
  backLeft.write(60);
  backRight.write(60);
  frontLeft.write(135);
  frontRight.write(135);
}

void leftYaw()
{
  backLeft.write(60);
  backRight.write(135);
  frontLeft.write(135);
  frontRight.write(60);
}

void rightYaw()
{
  backLeft.write(135);
  backRight.write(60);
  frontLeft.write(60);
  frontRight.write(135);
}

void readCommand()
{
  if(radio.available())
  {
    radio.read(&command, sizeof(command));
  }
}

void outOfRange()
{
  if(!radio.available())
  {
    hover();
  }
}

void loop() 
{

  if(radio.available())
  {
      if(command == 'H')
      {
        hover();
      }
      //Up Altitude
      if(command == 'U')
      {
        altitudeUp();
        }else{
        hover();
      }

      //Down Altitude
      if(command == 'D')
      {
        altitudeDown();
      }

      //Left Roll
      if(command == 'RL')
      {
        rollLeft();
      }

      //Right Roll
      if(command == 'RR')
      {
        rollRight();
      }

      //Front Roll or Pitch Down
      if(command == 'RF')
      {
        rollFront();
      } 

      //Back Roll or Pitch Up
      if(command == 'RB')
      {
        rollBack();
      }

      //Left Yaw
      if (command == 'YL')
      {
        leftYaw();
      }

      //Right Yaw
      if(command == 'YR')
      {
        rightYaw();
      }
      
  outOfRange();
  readCommand();
  }
}
