void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
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
    Serial.println("Y");
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
      Serial.println("X");
      delay( 500);
      }
  Serial.print(readPot2());
}
