/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(10, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  myservo.attach(9, 1000, 2000);  // attaches the servo on pin 9 to the servo object with servo min and max PWM
  myservo.write(pos);
  Serial.begin(9600);
}

void loop() {
  Serial.println(pos);
  if(digitalRead(8) == LOW)
  {
    while(digitalRead(8) == LOW)
    {}
    pos = pos+4 > 180 ?  180 : pos + 4;
    myservo.write(pos);
  }
  if(digitalRead(10) == LOW)
  {
    while(digitalRead(10) == LOW)
    {}
    pos = pos-4 < 0 ? 0 : pos - 4;
    myservo.write(pos);
  }
}
