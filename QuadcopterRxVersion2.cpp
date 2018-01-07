/*
NOTES:
jerome, you still need to add radio failsafes...

btw, you switched some whiles to ifs and ifs to whules

have a variable for trimming some values and changing speed, 
ie the ones where values are subtracted from. Make those 
variables so that they can be manipulated.	
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <Servo.h>

const byte address[5] = {'R','o','M','e','O'};

RF24 radio (9, 10);

long command;

bool newData = false;

//init all vars using previous code
/*motor 1 is CW, 2 is front right, 3 is back left, 4 is back right */

void setup(){
	radio.begin();
	radio.setDataRate(RF24_250KBPS);
	radio.setRetries(2, 15);
	radio.openReadingPipe(1, address);
	radio.startListening();
}

void loop(){
	bool armed = false;
	bool mode0 = true;

	preArm();

	flightMode0();

	flightMode1();

	changeMode();
}

void preArm()
{
	if(armed == false)
	{
		1.write(5);
		2.write(5);
		3.write(5);
		4.write(5);
		delay(4000);
		armed == true;
	}
}

void flightMode0()
{
	while(armed == true && mode0 = true)
	{
		if(radio.available())
		{
			radio.read(command,&sizeof(command));
			newData = true;
		}
		
		if(newData = true)
		
////////////////THROTTLE///////////////

			if(command >= 0 && command <= 200)
			{
				int throttle;
				throttle = command;
				1.write(throttle);
				2.write(throttle);
				3.write(throttle);
				4.write(throttle);
			}
		
/////////////////ROLL//////////////////

			if(command >= 1000 && command <= 1200)
			{
				int roll;
				roll = command - 1000;
				1.write(roll);
				2.write(roll -= 20);
				3.write(roll);
				4.write(roll -= 20);
			}

			if(command >= -1200 && command <= -1000)
			{
				int negRoll;
				negRoll = (command * -1) -1000;
				1.write(negRoll -= 10);
				2.write(negRoll);
				3.write(negRoll -= 10);
				4.write(negRoll);
			}

/////////////////PITCH/////////////////

			if(command >= 10000 && command <= 10200)
			{
				int pitch;
				pitch = command -= 10000;
				1.write(pitch -= 10);
				2.write(pitch -= 10);
				3.write(pitch);
				4.write(pitch);
			}

			if(command >= -10200 && command <= -10000)
			{
				int negPitch;
				negPitch = (command * -1) - 10000;
				1.write(negPitch);
				2.write(negPitch);
				3.write(negPitch -= 10);
				4.write(negPitch -= 10);
			}

/////////////////YAW///////////////////

			if(command >= 20000 && command <= 20200)
			{
				int yaw;
				yaw = command -= 20000;
				1.write(yaw);
				2.write(yaw -= 20);
				3.write(yaw -= 20);
				4.write(yaw);
			}

			if(command >= -20200 && command <= -20000)
			{
				int negYaw;
				negYaw = (command * -1) -20000;
				1.write(negYaw -= 20);
				2.write(negYaw);
				3.write(negYaw);
				4.write(negYaw -= 20);
			}
		
		newData = false;
		}
	}
}

void flightMode1(){
	//old flight mode settings here...
	while(armed == true && mode = 1){
		//main code belongs here...
		}
}

void changeMode(){
	if(command = 100000){
		mode0 = false;
		}

	if(command = 200000){
		mode0 = true;
	}
}
    
    
