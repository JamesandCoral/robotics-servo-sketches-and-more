#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int firstval;
int secondval;
int thirdval;
int fourthval;







void setup() {
  servo1.attach(13);
  servo2.attach(11);
  servo3.attach(10);
  servo4.attach(8);// put your setup code here, to run once:

}

void loop() {
  firstval = map(analogRead(0), 0 , 1023, 0, 180);
  servo1.write(firstval);
  delay(15);
  {
    secondval = map(analogRead(1), 0 , 1023, 0, 180);
    servo2.write(secondval);
    delay(15);
  }
  {
    thirdval = map(analogRead(2), 0 , 1023, 0, 180);
    servo3.write(thirdval);
    delay(15); 
  }
  {
    fourthval = map(analogRead(3), 0 , 1023, 0, 180);
    servo4.write(fourthval);
    delay(15); 
  }
 

}
