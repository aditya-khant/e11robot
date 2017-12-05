#define DISTSENSOR 14
#define REFLSENSOR 18
#define CREFLSENSOR 16
#define PHOTSENSOR 19
int dist;
int phot;
int refl;

void testSensors() { //this code was just used to read the reflectance values directly for calibration
  pinMode(REFLSENSOR, INPUT);
  refl = analogRead(REFLSENSOR-14);
  Serial.print("Reflectance: ");
  Serial.println(refl); 
  delay(1500);
}

void jumpoff(){ //the center robot would drive backward for 2.5 seconds, then stop.
  // this gave it ample time to fall off the back of the side robot and align itself with the wall.
  revControl(230,205);
  delay(2500);
  halt();
}

void fwd(){ 
  pinMode(REFLSENSOR, INPUT); //initializes the reflectance pin as input
  motorControl(100,70); //drives forward 
  //(recall the left motor is weaker than the right one, 
  // so we need a higher power level input on the left for the robot to drive forward)
  while(analogRead(REFLSENSOR-14) < 315){ //before hitting the black circle
    motorControl(100,70); //keep driving forward
  }
  halt(); //once the circle has been hit, and the loop is exited, stop
  revControl(50,100); //drive back briefly (this helps avoid colliding with the central blocks)
  delay(200);
}

void turnonblack(){
  while(analogRead(REFLSENSOR-14) > 315){ //while on the black circle
    motorControl(120,60); //drives right and forward
    gcloop(); // flashes one loop of the gold codes
  }
  halt(); //stops
}

void turnonwhite(){
  while(analogRead(REFLSENSOR-14) < 315){ //while on the white part of the board
     motorControl(60,120); //drives left and forward
     gcloop(); // flashes one loop of the gold codes
  }
  halt(); //stops
}
