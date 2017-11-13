int x = 0;
int m = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gcsetup();
  initMotors();
  // Go ahead and stop
  fwd();
  gcsetup();
  halt(); 
  delay(5);
  
}

void loop() {
  gcloop();
  //testSensors();
  turnonblack();
  turnonwhite();
}