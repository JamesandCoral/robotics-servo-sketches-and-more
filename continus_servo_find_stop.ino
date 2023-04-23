#include <Servo.h> //accesses the Arduino Servo Library

Servo myservo;  // creates servo object to control a servo

void setup()
{
  myservo.attach(12);
  Serial.begin(9600);// ensures output to servo on pin 9
}

void loop() 
{ 
  int val = map(analogRead(0), 0, 1023,800, 2000);     // converts reading from potentiometer to an output value in degrees of rotation that the servo can understand 
  myservo.writeMicroseconds(val);
  Serial.println(val);// sets the servo position according to the input from the potentiometer 
  delay(15);                           // waits 15ms for the servo to get to set position  
} 
