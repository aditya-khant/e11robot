// NOTE: NOT USED FOR SIDE ROBOT

#define DISTSENSOR 14
#define REFLSENSOR 18
#define CREFLSENSOR 16


// values of reflectance for arena
int rblack = 323;
int rwhite = 52;
int rred = 65;
int rblue = 230;

int dist;
int phot;
int refl;

void testSensors() {//Outputs value for refl sensor

  pinMode(REFLSENSOR, INPUT);

  refl = analogRead(REFLSENSOR-14);
   
  Serial.print("Reflectance: ");Serial.println(refl); 
  
  delay(1500);
}

void fwd(){ //go forward
  pinMode(REFLSENSOR, INPUT);
  setPowerLevel(90);
  while(analogRead(REFLSENSOR-14) < 300){
     forward();
  }
  halt();
}

void initialturn(){//First turn while line following
  pinMode(REFLSENSOR, INPUT);
  while(analogRead(REFLSENSOR-14) > 300){
    turnR();
  }
  halt();
  
}
void turnonblack(){ //turn right on black
  pinMode(REFLSENSOR, INPUT);
  while(analogRead(REFLSENSOR-14) > 300){
    motorControl(140,70);
  }
  halt();
  
}

void turnonwhite(){ // turn left on white
  pinMode(REFLSENSOR, INPUT);
  while(analogRead(REFLSENSOR-14) < 300){
     motorControl(70,140);
  }
  halt();
  
}



