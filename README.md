# ArduinoQuadopter

The code is very straightforward (I included some instructions in the code for the setup of some parts). You just have to tailor it for your needs, like if your quad is heavy, increase the (servoName).write values.

I used a PS2 controller as my remote control. I gutted the insides, tested for the potentiometer values, and wired everything to the Arduino. I also plan on using the extra buttons for some extra controls, like landing, takeoff, and an emergency landing (if the quad is to accidentally hit the ceiling...)

I wrote this code for my first "major" Arduino project. I chose to make a quadcopter because it was my interest at the time (and still is). I use 1 inch plywood for the fuselage and arms. My parts are the normal drone parts (battery, motors, ESCs, etc.).

The setup for the quad is:
  -4 brushless motors (RacerStar BR 2212) rated at 25A
  -4 propellers(duh! GemFan 6040)
  -4 ESCs (HW30A XXD)
  -Power Distribution Board (not required, but recommended)
  -4000mAh 45C 3S Lipo (XF Power)
  -Arduino Nano(remember this is Rx so of course there is a second Arduino)
  -NRF24L01+ PA LNA (same as previous part, this is Rx)
  
Pins 5 and 6 are the back motors, while pins 9 and 10 are the front motors. How I can find my sense
of direction is that the front left motor rotates CCW. You can also change the pins for your personal convenience.

The transmitter code is pretty straightforward...
