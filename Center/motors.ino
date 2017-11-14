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
  analogWrite(LEN, x);
  analogWrite(REN, m);
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
  analogWrite(LEN, y);
  analogWrite(REN, z);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS, LOW);
  digitalWrite(RPLUS, HIGH);
  digitalWrite(RMINUS, LOW);
}

//void setPowerLevel(int pwr){
 // m = pwr;
  //x = m * 0.2;
//}

