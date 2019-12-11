#include <Stepper.h>

const int CLOCKWISE = 1;
const int ANTI_CLOCKWISE = -1;

int STEPPER_MOTOR_PIN_1 = 2;
int STEPPER_MOTOR_PIN_2 = 3;
int STEPPER_MOTOR_PIN_3= 4;
int STEPPER_MOTOR_PIN_4 = 5;
int CLOCKWISE_BTN = 11;
int ANTI_CLOCKWISE_BTN = 12;
int STOP_BTN = 13;
int STEP = 36;  //To calculate the step we use 360 / x when x is the desired angle
bool runMotor;
int rotationDir;

Stepper myStepper(STEP, STEPPER_MOTOR_PIN_4, STEPPER_MOTOR_PIN_3, STEPPER_MOTOR_PIN_2, STEPPER_MOTOR_PIN_1);

void setup() {
  // initialize digital pin DC MOTOR PIN as an output.
  pinMode (STEPPER_MOTOR_PIN_1, OUTPUT);
  pinMode (STEPPER_MOTOR_PIN_2, OUTPUT);
  pinMode (STEPPER_MOTOR_PIN_3, OUTPUT);
  pinMode (STEPPER_MOTOR_PIN_4, OUTPUT);

  pinMode (CLOCKWISE_BTN, INPUT_PULLUP);
  pinMode (ANTI_CLOCKWISE_BTN, INPUT_PULLUP);
  pinMode (STOP_BTN, INPUT_PULLUP);
  // put your setup code here, to run once:
  myStepper.setSpeed(20);
  Serial.begin(9600);
  runMotor = true;
  rotationDir = CLOCKWISE;
}

void loop() {
  Serial.print(runMotor);
  Serial.print("***");
  if(runMotor)
  {
    myStepper.step(rotationDir);
  }
  
  if(digitalRead(CLOCKWISE_BTN) == LOW)
  {
    while(digitalRead(CLOCKWISE_BTN) == LOW)
    {}
    runMotor = true;
    rotationDir = CLOCKWISE;
  }

  if(digitalRead(ANTI_CLOCKWISE_BTN) == LOW)
  {
    while(digitalRead(ANTI_CLOCKWISE_BTN) == LOW)
    {}
    runMotor = true;
    rotationDir = ANTI_CLOCKWISE;
  }

  if(digitalRead(STOP_BTN) == LOW)
  {
    while(digitalRead(STOP_BTN) == LOW)
    {}
    runMotor = false;
  }
}
