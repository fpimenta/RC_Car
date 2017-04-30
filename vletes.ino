#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor left(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor right(1, MOTOR12_64KHZ);


SoftwareSerial BTSerial(12, 13);
void setup() {
  left.setSpeed(255);
  right.setSpeed(255);// set the speed to 200/255
  Serial.begin(9600);
  BTSerial.begin(9600);
  delay(500);
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
}
void loop() {
  char r;

  if (BTSerial.available()) {
    r = BTSerial.read();
  }
  if ( r == 'L') {
 
    left.run(RELEASE);      // turn it
    right.run(BACKWARD);
    Serial.println("right");
    delay(200);
    

  }
  if ( r == 'R') {
   
    left.run(BACKWARD);      // turn it
    right.run(RELEASE);
    Serial.println("left");
    delay(200);
   
  }
  if ( r == 'U') {
    
    left.run(BACKWARD);      // turn it
    right.run(BACKWARD);
    Serial.println("Forward");
    delay(200);
    
  }
  if ( r == 'B') {
   
    left.run(FORWARD);      // turn it
    right.run(FORWARD);
    Serial.println("Backwards");
    delay(200);
    
  }
  if ( r == 'S') {
    left.run(RELEASE);      // turn it
    right.run(RELEASE);
     
  }
  
   if ( r == 'T'){
      Serial.println("Taser");
      digitalWrite(7,HIGH);
      delay(1000);
      digitalWrite(7,LOW);

    }
 


}
// 13 RX bluetooth
// 12 TX bluetooth
                                                             
