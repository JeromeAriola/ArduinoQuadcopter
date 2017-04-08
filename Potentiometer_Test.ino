void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

int readPot(){
  return analogRead(14);
  }
  
void loop() {
  // put your main code here, to run repeatedly:
  if(readPot() <= 1023){
    Serial.print("Something...");
    delay(100);
    
    }else if(readPot() == 0 ){
      Serial.println("Nothing...");
      delay(100);
      }
  Serial.print(readPot());
}

