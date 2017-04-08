/*
Receiver Code(RX)/Quadcopter Side
The setup for the quad is 2 Arduino Nanos and 2 NRF24L01+ PA LNA radio modules.
The motors are brushless motors.
Pins 5 and 6 are the back motors, while pins 9 and 10 are the front motors. The front left motor rotates CCW.
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
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#include <SPI.h>
#include <Servo.h>
#include <printf.h>

Servo backLeft;
Servo backRight;
Servo frontLeft;
Servo frontRight;

#define CE_PIN 14     //A0 pin
#define CSN_PIN 15    //A1 pin

char command[3] =  

const byte address[6] = "00001";    //this simply specifies the 'address' that I will be using

RF24 receiver(CE_PIN, CSN_PIN);

/*
This part I think should be edited out because since 03/30/2017 I learned to use servo Write
It can be used for a brushed motor quad in the future
  const int backLeft = 5;
  const int backRight = 6;
  const int frontLeft = 9;
  const int frontRight = 10;
*/  

int changeMovementVal(){
  if(radio.available() ){
    radio.read(&command, )
    }
  }

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
void setup()
{
  backLeft.attach(5);
  backRight.attach(6);
  frontLeft.attach(9);
  frontRight.attach(10);
  
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  radio.begin();
  radio.setPayloadSize(8);
  radio.openReadingPipe(0, address);
  radio.setRetries(15, 15);
}

void loop() 
{
  //Up Altitude
  if(/*receive message "U"*/)
  {
   altitudeUp();
    }else{
  	hover();
  }

  //Down Altitude
  if(/*receive message "D"*/)
  {
	altitudeDown();
    }else{
  	hover();
  }

  //Left Roll
  if(/*receive message RL*/)
  {
	rollLeft();
    }else{
  	hover();
  }

  //Right Roll
  if(/*receive message RR*/)
  {
  	rollRight();
    }else{
  	hover();
  }

  //Front Roll or Pitch Down
  if(/*receive message RF*/)
  {
  	rollFront();
    }else{
  	hover();
  }

  //Back Roll or Pitch Up
  if(/*receive message RB*/)
  {
	rollBack();
  }else{
  	hover();
  }

  //Left Yaw
  if (/*receive message YL*/)
  {
	leftYaw();
    }else{
  	hover();
  }

  //Right Yaw
  if(/*receive message YR*/)
  {
	rightYaw();
    }else{
  	hover();
  }
}
