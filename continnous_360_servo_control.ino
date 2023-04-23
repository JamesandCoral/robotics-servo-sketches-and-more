#include <Servo.h>

Servo myservo;

const int servoStop = 1463;
const int servoSpeed = 50;
int potVal;
int potStop;
unsigned int servoStart;



void setup() {
  myservo.attach(11);// put your setup code here, to run once:

}

void loop() {
  
  potVal = map(analogRead(0), 0, 1023, 0, 65000);
  
    if (potVal > potStop) {
      
      int potSpeed = potStop - potVal;
      servoStart = servoStop + (servoSpeed + potSpeed);
      myservo.writeMicroseconds(servoStart);
      // put your main code here, to run repeatedly:
    }

    else if (potVal < potStop){
      int potSpeed = potStop - potVal;
      servoStart = servoStop - (servoSpeed - potSpeed);
      myservo.writeMicroseconds(servoStart);
      
    }

    else myservo.writeMicroseconds(servoStop);


   potStop = potVal;
   servoStart = 0;

   delay(15);

}
