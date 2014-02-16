#include <Servo.h>

Servo servo1;
const int trigPin = 13;
const int echoPin = 12;
const int buzzer = 7;

void setup() {
  servo1.attach(10);
  pinMode(buzzer,OUTPUT);
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
    servo1.write(150); 
    digitalWrite(buzzer,HIGH);
    delay(10);
    digitalWrite(buzzer,LOW);
    delay(15);
  } 
  else {   
    servo1.write(0);  
    digitalWrite(buzzer,LOW);
    delay(15);                      
  }

  Serial.print(inches);
  Serial.println(" inches");
  delay(250);  

}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}




