int x = 0;
int m = 0;
int clockwise = 0;

//int durationIn = 1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  cwTest(); //checks if we should be going clockwise or not
  initMotors();
  gcsetup(); //sets up the gold code
  jumpoff();
//  // Go ahead and stop
  if (clockwise == false){
    fwd();
  }
  else{
    ccfwd(); //counterclockwise
  }
  halt(); 
  delay(5);
//  
}

void loop() {
 if (clockwise == false){
   gcloop();
   turnonblack();
   turnonwhite();
  }
 else{
   //counterclockwise
   ccturnonblack();
   ccturnonwhite();
  }
}
