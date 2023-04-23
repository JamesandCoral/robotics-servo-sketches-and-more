#include <Servo.h>
Servo Servo1;
int AnalogOut = 0;
int NewAnalogOut = 0;
int pin_Button = 9;
int pin_Button_State = 0;
int pin_Button_State_Last = 0;
int storage[800];
int storage_loc = 0;
int recording = 0;





void setup() {
  Serial.begin(9600);
  Servo1.attach(10);
  pinMode(pin_Button, INPUT);
  // put your setup code here, to run once:
}

void loop() {
  pin_Button_State = digitalRead(pin_Button);
  if (pin_Button_State != pin_Button_State_Last) {
    if (pin_Button_State == HIGH) {
      recording++;
      if (recording == 2) {
        storage[storage_loc] = 777;
        // put your main code here, to run repeatedly:
      }
    }
    delay(50);
  }
  

  if (recording == 0) {
    int sensorValue = analogRead(A0);
    NewAnalogOut = map(sensorValue, 0, 1023, 0, 180);
    if (abs(NewAnalogOut - AnalogOut) > 2) {
      Servo1.write(AnalogOut);
      AnalogOut = NewAnalogOut;
      
    }
  }
  delay(1);
  if ( recording == 1) {
    recording = 1;
    if (storage_loc < 800) {
      storage[storage_loc] = NewAnalogOut;
      delay(100);
      Serial.println(storage[storage_loc]);
      storage_loc++;
      
    }
  } else if (recording > 1) {
    storage_loc = 0;
    while (storage_loc < 800 && storage[storage_loc] != 777) {
        Servo1.write(storage[storage_loc]);
        delay(100);
      }
      recording = 0;
    }
  }
