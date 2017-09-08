/*The ESCs I use only have about 9 speed settings.
  The servo values for the speeds (in order) are
  30, 40, 50, 60, 70, 80, 90, 120, and 170.
*/

#include <nRF24L01.h>
#include <RF24.h>

#include <SPI.h>
#include <Servo.h>

Servo cameraServo;
Servo backLeft;
Servo backRight;
Servo frontLeft;
Servo frontRight;

#define CE_PIN 14     //A0 pin
#define CSN_PIN 15    //A1 pin

int GlobalCameraAdjust;

bool cameraAdjust = false;

char command;

const byte address[6] ="00001" ;    //this simply specifies the 'address' that I will be using

RF24 radio(CE_PIN, CSN_PIN);

void setup()
{
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPayloadSize(8);
  radio.openReadingPipe(0, 00001);
  radio.setRetries(1, 15);
  radio.startListening();

  cameraServo.attach(4);
  backLeft.attach(5);
  backRight.attach(6);
  frontLeft.attach(9);
  frontRight.attach(10);
  
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
 
}

//Movement Functions --not tested with drone; full of assumptions

void hover()
{
  backLeft.write(40);           //this simply assumes that half speed is like half
  backRight.write(40);          //turn in a servo
  frontLeft.write(40);
  frontRight.write(40);
}

void altitudeUp()
{
  backLeft.write(120);
  backRight.write(120);
  frontLeft.write(120);
  frontRight.write(120);
}

void altitudeDown()
{
  backLeft.write(30);
  backRight.write(30);
  frontLeft.write(30);
  frontRight.write(30);
}

void rollLeft()
{
  backLeft.write(60);
  backRight.write(120);
  frontLeft.write(60);
  frontRight.write(120);
}

void rollRight()
{
  backLeft.write(120);
  backRight.write(60);
  frontLeft.write(120);
  frontRight.write(60);
}

void rollFront()
{
  backLeft.write(120);
  backRight.write(120);
  frontLeft.write(60);
  frontRight.write(60);
}

void rollBack()
{
  backLeft.write(60);
  backRight.write(60);
  frontLeft.write(120);
  frontRight.write(120);
}

void leftYaw()
{
  backLeft.write(60);
  backRight.write(120);
  frontLeft.write(120);
  frontRight.write(60);
}

void rightYaw()
{
  backLeft.write(120);
  backRight.write(60);
  frontLeft.write(60);
  frontRight.write(120);
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

  if(command == 'ADJUSTCAM')
  {
    cameraAdjust = true;
  }
  else if(command == 'ADJUSTEDCAM')
  {
    cameraAdjust = false;
  }

  while(cameraAdjust = true)
  {
    int cameraServoVal = 30;
    while(command == 'U')
    {
      cameraServoVal +=5;
      delay(100);
      if(cameraServoVal > 180)
      {
        break;
      }
    }
    while(command == 'D')
    {
      cameraServoVal -= 5;
      delay(100);
      if(cameraServoVal < 30)
      {
        break;
      }
    }
    int GlobalCameraAdjust = cameraServoVal;
    cameraServo.write(cameraServoVal);
  }

  
  
  outOfRange();
  readCommand();
  }
}
