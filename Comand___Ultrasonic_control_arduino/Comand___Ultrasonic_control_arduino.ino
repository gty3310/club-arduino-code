#include <Servo.h>
#include "Ultrasonic.h"
Ultrasonic myultrasonic(2,3);
Servo turningservo;
Servo drivemotor;
int input = 0;       
void setup() {
  turningservo.attach(9); 
  drivemotor.attach(12);
  Serial.begin(9600);
}        
void motor(int val) {
  drivemotor.write(val+90);
  delay(100);
}
void turnright(){
  turningservo.write(110);
  delay(100);
}
void turnleft(){
  turningservo.write(60);
  delay(100);
}
void forward(){
  motor(0);
  delay(50);  
  motor(10);
  delay(50); 
}
void backward(){
  motor(0);
  delay(50);  
  motor(-5);
  delay(50); 
}
void carstop(){
  motor(0);
  delay(50);  
}
void loop () {
  if (myultrasonic.Ranging(CM)<40){
    backward();
    Serial.println("back");
  } 
  if (myultrasonic.Ranging(CM)>40){
    forward();
    Serial.println("front");
  } 
  input = Serial.read(); 
  switch(input) {
  case 'R':
    turnright();
    Serial.println("right");
    break;
  case 'L':
    turnleft();
    Serial.println("left");
    break;
  case 'F':
    forward();
    Serial.println("front");
    break;
  case 'B':
    backward();
    Serial.println("back");
    break;
  case 'S':
    carstop();
    Serial.println("stop");
    break;
  }
}





