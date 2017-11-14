#define RPLUS 7
#define RMINUS 12
#define LPLUS 9
#define LMINUS 8
#define LEN 6
#define REN 11

// int powerLevel = 255;

void initMotors(){
  pinMode(RPLUS, OUTPUT);
  pinMode(RMINUS, OUTPUT);
  pinMode(LPLUS, OUTPUT);
  pinMode(LMINUS, OUTPUT);
  pinMode(LEN, OUTPUT);
  pinMode(REN, OUTPUT);
}
void halt(){
  analogWrite(LEN, x);
  analogWrite(REN, m);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, LOW);
  digitalWrite(RPLUS, LOW);
  digitalWrite(RMINUS, LOW);
}

void forward(){
  analogWrite(LEN, x);
  analogWrite(REN, m);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS, LOW);
  digitalWrite(RPLUS, HIGH);
  digitalWrite(RMINUS, LOW);
}

void backward(){
  analogWrite(LEN, 225);
  analogWrite(REN, 225);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, HIGH);
  digitalWrite(RPLUS, LOW);
  digitalWrite(RMINUS, HIGH);
}

void turnL(){
  analogWrite(LEN, x);
  analogWrite(REN, m);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, HIGH);
  digitalWrite(RPLUS, HIGH);
  digitalWrite(RMINUS, LOW);
}

void turnR(){
  analogWrite(LEN, x);
  analogWrite(REN, m);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS, LOW);
  digitalWrite(RPLUS, LOW);
  digitalWrite(RMINUS, HIGH);
}

void motorControl(int y, int z){
  if (y > 0){
  analogWrite(LEN, y);
  
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS, LOW);
  
  } else {
    analogWrite(LEN, abs(y));
  
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, HIGH);
  
  }

  if (z > 0){
  analogWrite(REN, z);
  
  digitalWrite(RPLUS, HIGH);
  digitalWrite(RMINUS, LOW);
  
  } else {
    analogWrite(REN, abs(y));
  
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS, HIGH);
  
  }
  analogWrite(LEN, y);
  analogWrite(REN, z);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS, LOW);
  digitalWrite(RPLUS, HIGH);
  digitalWrite(RMINUS, LOW);
}

void setPowerLevel(int pwr){
  x = pwr;
  m = x * 0.75;
}

void runAway(){
  halt();
  motorControl(0, 255);
  delay(450);
  motorControl(255, 200);
  delay(1500);
  halt();
  
}

void setupMove(){
  delay(2000);
  motorControl(-255, 255);
  delay(750);
  halt();
}


