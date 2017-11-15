#define DISTSENSOR 14
#define REFLSENSOR 18
#define CREFLSENSOR 16
#define PHOTSENSOR 19

// values of reflectance for arena
int rblack = 323;
int rwhite = 52;
int rred = 65;
int rblue = 230;

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
void fwd(){
  pinMode(REFLSENSOR, INPUT);
//  setPowerLevel(95);
  motorControl(83,56);
  delay(300);
  while(analogRead(REFLSENSOR-14) < 300){
     //forward();
     //
  }
  halt();
}

//void initialturn(){
//  pinMode(REFLSENSOR, INPUT);
//  while(analogRead(REFLSENSOR-14) > 300){
//    turnR();
//  }
//  halt();
//  
//}
void turnonblack(){
  pinMode(REFLSENSOR, INPUT);
  while(analogRead(REFLSENSOR-14) > 300){
    motorControl(120,60);
    gcloop();
    calcDist();
  }
  halt();
  
}

void turnonwhite(){
  pinMode(REFLSENSOR, INPUT);
  while(analogRead(REFLSENSOR-14) < 300){
     motorControl(60,120);
     gcloop();
     calcDist();
  }
  halt();
  
}

void avoidCrash(){
   if (durationIn < 10);
   {
    while (true){
     while(analogRead(REFLSENSOR-14) > 300){ //reverse on black
       revControl(60,120);
       gcloop();
       calcDist();
      } 
     halt();
     while(analogRead(REFLSENSOR-14) < 300){ //reverse on white
      revControl(120,60);
      gcloop();
      calcDist();
      }
     halt();
    }
   }
} 

