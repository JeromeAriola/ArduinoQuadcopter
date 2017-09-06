void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

int readPot4(){
  return analogRead(16);
  }
int readPot3(){
  return analogRead(17);
  }

int readPot2(){
  return analogRead(18);
  }

int readPot1(){
  return analogRead(19);
  }
  
void loop() {
  // put your main code here, to run repeatedly:
  if(readPot1() <= 1023){
    Serial.println("X");
    delay(500);
    
    }else if(readPot1() == 0 ){
      Serial.println("Y");
      delay( 500);
      }
  Serial.print(readPot1());

    if(readPot2() <= 1023){
    Serial.println("X");
    delay( 500);
    
    }else if(readPot2() == 0 ){
      Serial.println("Y");
      delay( 500);
      }
  Serial.print(readPot2());

    if(readPot3() <= 1023){
    Serial.println("Y");
    delay(500);
    
    }else if(readPot3() == 0 ){
      Serial.println("X");
      delay( 500);
      }
  Serial.print(readPot1());

    if(readPot4() <= 1023){
    Serial.println("Y");
    delay( 500);
    
    }else if(readPot4() == 0 ){
      Serial.println("X");
      delay( 500);
      }
  Serial.print(readPot2());
}
