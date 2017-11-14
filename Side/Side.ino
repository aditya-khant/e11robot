int x = 0;
int m = 0;
bool isWhite = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, INPUT);
  isWhite = digitalRead(3);
  initMotors();
  initUS();
  setupMove();
  
  

}

void loop() {
  //testSensors();
  while (!(detectGoldCode())){
    motorControl(255,225);
  }
  if (detectGoldCode()){
    runAway();
  }
}
