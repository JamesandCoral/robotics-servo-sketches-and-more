
/* A simple program to sequentially turn on and turn off 3 LEDs */ 

int LED1 = 13;
int LED2 = 12;
int LED3 = 11;

#include <Servo.h> //accesses the Arduino Servo Library

Servo myservo;  // creates servo object to control a servo

int val;    // variable to read the value from the analog pin


void setup() {
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
   {
  myservo.attach(9);  // ensures output to servo on pin 9
   }
}


void loop() {
  digitalWrite(LED1, HIGH);    // turn on LED1 
  delay(300);
  digitalWrite(LED1, LOW);
  delay(200);                  // wait for 200ms
  digitalWrite(LED2, HIGH);    // turn on LED2
  delay(300);
  digitalWrite(LED2, LOW);
  delay(300);                      // wait for 200ms       
  digitalWrite(LED3, HIGH);    // turn on LED3 
  delay(300);
  digitalWrite(LED3, LOW);       // wait for 200ms
  delay(1000);                  // wait for 300ms before running program all over again
  { 
  val = analogRead(1);            // reads the value of the potentiometer from A1 (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 180);     // converts reading from potentiometer to an output value in degrees of rotation that the servo can understand 
  myservo.write(val);                  // sets the servo position according to the input from the potentiometer 
  delay(0);                           // waits 15ms for the servo to get to set position  
  }
}
