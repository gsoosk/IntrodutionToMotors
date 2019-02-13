int DC_MOTOR_PIN_1 = 9;
int DC_MOTOR_PIN_2 = 10;
int STOP_START_BTN = 13;
int INC_SPEED_BTN = 12;
int DEC_SPEED_BTN = 11;
int REVERSE_ROTATE_BTN = 8;
bool motorIsOn;
int motorSpeed;
int temp;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin DC MOTOR PIN as an output.
  pinMode (DC_MOTOR_PIN_1, OUTPUT);
  pinMode (DC_MOTOR_PIN_2, OUTPUT);

  // 
  pinMode (STOP_START_BTN, INPUT_PULLUP);
  pinMode (INC_SPEED_BTN, INPUT_PULLUP);
  pinMode (DEC_SPEED_BTN, INPUT_PULLUP);
  pinMode (REVERSE_ROTATE_BTN, INPUT_PULLUP);
  
  motorIsOn = true;
  motorSpeed = 255;
  
}

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(STOP_START_BTN) == LOW)
  {
    while(digitalRead(STOP_START_BTN) == LOW)
    {}
    motorIsOn = !motorIsOn;
  }
  if(digitalRead(INC_SPEED_BTN) == LOW)
  {
    while(digitalRead(INC_SPEED_BTN) == LOW)
    {}
    motorSpeed = (motorSpeed + 10) > 255 ? 255 : motorSpeed + 10;    
  }
  if(digitalRead(DEC_SPEED_BTN) == LOW)
  {
    while(digitalRead(DEC_SPEED_BTN) == LOW)
    {}
    motorSpeed = (motorSpeed - 10) < 0 ? 0 : motorSpeed - 10;    
  }
  if(digitalRead(REVERSE_ROTATE_BTN) == LOW)
  {
    while(digitalRead(REVERSE_ROTATE_BTN) == LOW)
    {}
    temp = DC_MOTOR_PIN_1;
    DC_MOTOR_PIN_1 = DC_MOTOR_PIN_2;
    DC_MOTOR_PIN_2 = temp;
  }
  
  if(motorIsOn)
    analogWrite(DC_MOTOR_PIN_1, motorSpeed);
  else
    analogWrite(DC_MOTOR_PIN_1, 0);
    
  analogWrite(DC_MOTOR_PIN_2, 0);
  
}
