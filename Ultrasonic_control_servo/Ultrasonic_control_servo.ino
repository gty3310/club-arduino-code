#include <Servo.h>
#include "Ultrasonic.h"
Ultrasonic myultrasonic(2,3);
Servo turningservo;
Servo drivemotor;
Servo myservo;
int input = 0;    
int x=0;
int pos=0;
void setup() {
  turningservo.attach(9); 
  drivemotor.attach(12);
  Serial.begin(9600);
  myservo.attach(6);
}        


void loop () {
  input = Serial.read();  
  if (input == 'R' ) {
    turningservo.write(110);
    Serial.println("right");
  } 
  if (input == 'L'){
    turningservo.write(60);
    Serial.println("left");
  } 
  x=myultrasonic.Ranging(CM);
  Serial.println(x);
  delay(10);
  if (x > 40)
  {
    Serial.println("move"); 
    for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      if (myultrasonic.Ranging(CM)<40){
        delay(10);
      }
      else{ 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(10);  
      }                     // waits 15ms for the servo to reach the position 
    } 
    for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
      if (myultrasonic.Ranging(CM)<40){
        delay(10);
      }
      else{
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(10);    
      }     
    }
  } 
  else 
  {
    Serial.println("stop");
    delay(10);
  }
}









