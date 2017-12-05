#define RPLUS 7
#define RMINUS 12
#define LPLUS 9
#define LMINUS 8
#define LEN 6
#define REN 11
//defines the above pins, which we later use to control the motors.


void initMotors(){ //sets all of the motor pins as output pins
  pinMode(RPLUS, OUTPUT);
  pinMode(RMINUS, OUTPUT);
  pinMode(LPLUS, OUTPUT);
  pinMode(LMINUS, OUTPUT);
  pinMode(LEN, OUTPUT);
  pinMode(REN, OUTPUT);
}

void halt(){ // turns off all motors to stop the robot.
  analogWrite(LEN, x);
  analogWrite(REN, m);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, LOW);
  digitalWrite(RPLUS, LOW);
  digitalWrite(RMINUS, LOW);
}

void motorControl(int y, int z){ 
  //drives forward, but because the motor power levels can be unequal, it could also turn one way
  analogWrite(LEN, y);
  analogWrite(REN, z);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS, LOW);
  digitalWrite(RPLUS, HIGH);
  digitalWrite(RMINUS, LOW);
}

void revControl(int y, int z){ // same as motorControl, but for driving backward
  analogWrite(LEN, y);
  analogWrite(REN, z);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, HIGH);
  digitalWrite(RPLUS, LOW);
  digitalWrite(RMINUS, HIGH);
}

