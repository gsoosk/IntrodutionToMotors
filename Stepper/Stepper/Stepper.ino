#include <Stepper.h>

int STEPPER_MOTOR_PIN_1 = 2;
int STEPPER_MOTOR_PIN_2 = 3;
int STEPPER_MOTOR_PIN_3= 4;
int STEPPER_MOTOR_PIN_4 = 5;
int CLOCKWISE_BTN = 11;
int ANTI_CLOCKWISE_BTN = 12;
int STOP_BTN = 13;
int STEP = 36;  //To calculate the step we use 360 / x when x is the desired angle

Stepper myStepper(STEP, STEPPER_MOTOR_PIN_1, STEPPER_MOTOR_PIN_2, STEPPER_MOTOR_PIN_3, STEPPER_MOTOR_PIN_4);

void setup() {
  // initialize digital pin DC MOTOR PIN as an output.
  pinMode (STEPPER_MOTOR_PIN_1, OUTPUT);
  pinMode (STEPPER_MOTOR_PIN_2, OUTPUT);
  pinMode (STEPPER_MOTOR_PIN_3, OUTPUT);
  pinMode (STEPPER_MOTOR_PIN_4, OUTPUT);
  // put your setup code here, to run once:
    myStepper.setSpeed(40);
    Serial.begin(9600);
}

void loop() {
   if(digitalRead(CLOCKWISE_BTN) == LOW)
  {
    while(digitalRead(CLOCKWISE_BTN) == LOW)
    {}
     Serial.println("clockwise");
     myStepper.step(STEP);
  }

     if(digitalRead(ANTI_CLOCKWISE_BTN) == LOW)
  {
    while(digitalRead(ANTI_CLOCKWISE_BTN) == LOW)
    {}
     Serial.println("anti-clockwise");
     myStepper.step(-STEP);
  }
}
