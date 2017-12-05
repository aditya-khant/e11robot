int x = 0;
int m = 0;
#define trigpin 17
#define echopin 16
// sets up pins and variables
// x and m were initially used in a function called setMotorPower 
// to change the power output of the motors, but because we ended up using motorControl,
// variables x and m were only kept for the halt() function.

void setup() {
  Serial.begin(9600); // initialize Serial
  initMotors(); // initialize the motors
  gcsetup(); //sets up the gold code
  jumpoff(); //lets the center robot roll off the back of the side robot
  fwd(); //drives forward until a black line is hit
  halt(); //it stops instantly
  delay(5); //and waits for a brief moment
//  
}

void loop() {
   turnonblack(); //if the reflectance sensor sees black, it drives right and forward
   turnonwhite(); //if it sees white, it drives left and forward
}
