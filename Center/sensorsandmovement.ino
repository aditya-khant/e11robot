#define DISTSENSOR 14
#define REFLSENSOR 18
#define CREFLSENSOR 16
#define PHOTSENSOR 19
int dist;
int phot;
int refl;

void testSensors() {

  pinMode(REFLSENSOR, INPUT);

  refl = analogRead(REFLSENSOR-14);
   
  Serial.print("Reflectance: ");
  Serial.println(refl); 
  
  delay(1500);
}
void jumpoff(){
  revControl(230,205);
  delay(2500);
  //revControl(60,120);
  //delay(300);
  halt();
}
void fwd(){
  pinMode(REFLSENSOR, INPUT);
//  setPowerLevel(95);
  motorControl(100,70);
  delay(1000);
  while(analogRead(REFLSENSOR-14) < 315){
    motorControl(100,70);
  }
  halt();
  revControl(50,100);
  delay(200);
}

void turnonblack(){
  pinMode(REFLSENSOR, INPUT);
  while(analogRead(REFLSENSOR-14) > 315){
    //motorControl(130,65);
    //motorControl(120,55);
    motorControl(120,60);
    //motorControl(140,60);
    //motorControl(150,75);
    //motorControl(240,120);
    gcloop();
    //calcDist();
  }
  halt();
  
}

void turnonwhite(){
  pinMode(REFLSENSOR, INPUT);
  while(analogRead(REFLSENSOR-14) < 315){
     //motorControl(65,130);
     //motorControl(60,110);
     motorControl(60,120);
     //motorControl(60,140);
     //motorControl(70,150);
     //motorControl(240,120);
     gcloop();
     //calcDist();
  }
  halt();
  
}
