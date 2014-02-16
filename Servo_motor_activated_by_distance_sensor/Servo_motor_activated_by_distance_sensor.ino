#include <Servo.h>
// DC hobby servo
Servo servo1;
const int trigPin = 13;
const int echoPin = 12;
int pos = 0;

void setup() {
  servo1.attach(10);
  Serial.begin(9600);
}

void loop() {

  long duration, inches;

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  inches = microsecondsToInches(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.println();

  if (inches < 6) {     
    if(pos < 180){  
      servo1.write(180);  
      pos = 180;   
      delay(15);
    }
  } 
  else {   
    if(pos > 0){  
      servo1.write(0);  
      pos = 0;  
     delay(15); 
    }                       
  }

  Serial.print(inches);
  Serial.println(" inches");
  delay(250);  

}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

