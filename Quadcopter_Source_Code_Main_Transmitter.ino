/*
Transmitter Code for TX
*/

//I should have functions where it automatically sends if potentiometer
//values are what they are I tell them to be (i.e. up on the potentiometer, 
//then the up() function will execute sending the "U" string)

#include <stdio.h>
#include <printf.h>
#include <nRF24L01.h>
#include <RF24_config.h>
#include <RF24.h>

//Left Potentiometer Shortcuts in Code
#define up /*leftPotentiometer up voltage value*/           //or maybe I can switch
#define down /*leftPotentiometer down voltage value*/       //for a const int
#define left /*leftPotentiometer left voltage value*/
#define right /*leftPotentiometer right voltage value*/

#define up /*rightPotentiometer up voltage value*/
#define down /*rightPotentiometer down voltage value*/
#define left /*rightPotentiometer left voltage value*/
#define right /*rightPotentiometer right voltage value*/
 
#define CE_PIN   14
#define CSN_PIN 15

const int leftPot = 14; //A0
const int rightPot = 15; //A1

const byte address[6] = "00001";

char rollForward[3] = "RF";
char rollBackward[3] = "RB"; 
char leftYaw[3] = "YL";
char rightYaw[3] = "YR";

char rollRight[3] = "RR";
char rollLeft[3] = "RL";
char up[3] = 'U'
char down[3] = 'D'

RF24 transmitter(CE_PIN, CSN_PIN);

//Left Potentiometer Commands
char rollForward = "RF"
char rollBack = "RB"
char yawLeft = "YL"
char yawRight = "YR"

//Right Potentiometer Commands
char altitudeUp = 'U'
char altitudeDown = 'D'
char rollLeft = "RL"
char rollRight = "RR"



void setup(){
  pinMode(leftPot, INPUT);
  pinMode(rightPot, INPUT);

  radio.begin();
  radio.setPayloadSize(8);
  radio.openWritingPipe(0, address);
  radio.setRetries(15, 15);
}

int readLeftPot(){
  return analogRead(leftPot);
}

int readRightPot(){
  return analogRead(rightPot);
}

void loop(){
  int leftPotValue = readLeftPot();
  int rightPotValue =  readRightPot();

//Right Potentiometer Conditionals  
  if(rightPotValue == /*pot value for up*/){
    /*send a message U in serial monitor */
    }

  if(rightPotValue == /*pot value for down*/){
    /*serialWrite D*/
    /*send the message via radio and serial monitor*/
    }

  if(rightPotValue == /*pot value for left roll*/){
    /*serialWrite RL*/
    /*send the message via radio and serial monitor*/
    }
  if(rightPotValue == /*pot value for right roll*/){
    /*serialWrite RR*/
    }

//Left Potentiometer Conditionals
  if(leftPotValue == /*pot value for forward roll*/){
    /*send the message RF*/
    }
    
  if(leftPotValue == /*pot value for back roll*/){
    /*send the message RB*/
    }

  if(leftPotValue == /*pot value for left yaw*/){
    /*send the message YL*/
    }
    
  if(leftPotValue == /*pot value for right yaw*/){
    /*send the message YR*/
    }
}

