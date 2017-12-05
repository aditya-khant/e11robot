
//Initialize Pins
#define RPLUS 7
#define RMINUS 12
#define LPLUS 9
#define LMINUS 8
#define LEN 6
#define REN 11

// int powerLevel = 255;

void initMotors(){ // Initialize Motors
  pinMode(RPLUS, OUTPUT);
  pinMode(RMINUS, OUTPUT);
  pinMode(LPLUS, OUTPUT);
  pinMode(LMINUS, OUTPUT);
  pinMode(LEN, OUTPUT);
  pinMode(REN, OUTPUT);
}
void halt(){ //Halt all motors
  analogWrite(LEN, x);
  analogWrite(REN, m);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, LOW);
  digitalWrite(RPLUS, LOW);
  digitalWrite(RMINUS, LOW);
}

void forward(){ // Go Forward 
  analogWrite(LEN, x);
  analogWrite(REN, m);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS, LOW);
  digitalWrite(RPLUS, HIGH);
  digitalWrite(RMINUS, LOW);
}

void backward(){ // Go Backwards
  analogWrite(LEN, 225);
  analogWrite(REN, 225);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, HIGH);
  digitalWrite(RPLUS, LOW);
  digitalWrite(RMINUS, HIGH);
}

void turnL(){ //Turn Left
  analogWrite(LEN, x);
  analogWrite(REN, m);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, HIGH);
  digitalWrite(RPLUS, HIGH);
  digitalWrite(RMINUS, LOW);
}

void turnR(){ //turn Right
  analogWrite(LEN, 255);
  analogWrite(REN, 255);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS, LOW);
  digitalWrite(RPLUS, LOW);
  digitalWrite(RMINUS, HIGH);
}

void motorControl(int y, int z){ //Custom motor control to control each individual motor
  if (y > 0){ // if y is positive
  analogWrite(LEN, y); // Write power to Left
  //Go forward
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS, LOW);
  
  } else {
  analogWrite(LEN, abs(y));//Write abs power to Left
  //Go back
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, HIGH);
  
  }

  if (z > 0){ //if z is positive
  analogWrite(REN, z);// Write power to Z
  //Right go forward
  digitalWrite(RPLUS, HIGH);
  digitalWrite(RMINUS, LOW);
  
  } else {
    analogWrite(REN, abs(y)); //write abs power to Right
  //Left go forward. While this was a coding error, fixing it worsened our robot. 
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, HIGH);
  
  }
}

void setPowerLevel(int pwr){ // Motor Power Library
  x = pwr;
  m = x * 0.75;
}

void runAway(){ //Stop, turn left, run into the wall
  halt();
  motorControl(0, 255);
  delay(450);
  motorControl(255, 200);
  delay(1500);
  halt();
  
}

void setupMove(){// Wait for 1s go straight, and then turn Right into the wall
  delay(1000);
  motorControl(255, 255);
  delay(1000);
  turnR();
  delay(300);
  
}


