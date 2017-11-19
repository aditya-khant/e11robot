#define boopPin 13
#define boopOut 5
#define returnTime 50000

int x = 0;
int m = 0;
bool isWhite = true;
long whendidwestart = millis();

void setup() {
  // put your setup code here, to run once:
  long startTime = millis();
  bool letsReturn = false;
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(boopPin, INPUT);
  pinMode(boopOut, OUTPUT);
  digitalWrite(boopOut, HIGH);
  digitalWrite(4, OUTPUT);
  whendidwestart = millis();
  isWhite = digitalRead(3);
  initMotors();
  //initUS();
  setupMove();


}

void loop() {
  workingWithReturn();
  
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


void workingWithReturn(){
  
  while (!(detectGoldCode()) and !(digitalRead(boopPin))) {
    
    motorControl(255, 240);
    returnStrat();
    
  }
  if (detectGoldCode() ) {
    
    returnStrat();
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



