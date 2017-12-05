int x = 0;
int m = 0;
int clockwise = 0;
#define trigpin 17
#define echopin 16
int BLACK = 315;
int WHITE = 200;

//int durationIn = 1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initMotors();
  gcsetup(); //sets up the gold code
  jumpoff();
  fwd();
  halt(); 
  delay(5);
//  
}

void loop() {
   turnonblack();
   turnonwhite();
}
