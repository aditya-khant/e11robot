#define boopPin 13
#define boopOut 5

int x = 0;
int m = 0;
bool isWhite = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(boopPin, INPUT);
  pinMode(boopOut, OUTPUT);
  digitalWrite(boopOut, HIGH);
  isWhite = digitalRead(3);
  initMotors();
  initUS();
  setupMove();



}

void loop() {
  workingWithoutReturn();
  
}

void workingWithoutReturn(){
  while (!(detectGoldCode()) and !(digitalRead(boopPin))) {
    motorControl(255, 240);
  }
  if (detectGoldCode() ) {
    runAway();
  }
  if (digitalRead(boopPin)) {
    halt();
    while (digitalRead(boopPin)) {
      motorControl(255, -255);
      delay(400);
    }
  }
}

