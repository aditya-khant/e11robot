#define DISTSENSOR 14
#define REFLSENSOR 18
#define CREFLSENSOR 16
#define PHOTSENSOR 19


#define CW 10 //lol

void cwTest(){
  clockwise = (digitalRead(10));
}

void ccfwd(){
  pinMode(REFLSENSOR, INPUT);
//  setPowerLevel(95);
  motorControl(83,65);
  delay(300);
  while(analogRead(REFLSENSOR-14) < 300){
     //forward();
     //
  }
  halt();
  motorControl(0,30);
  delay(100);
}

//void initialturn(){
//  pinMode(REFLSENSOR, INPUT);
//  while(analogRead(REFLSENSOR-14) > 300){
//    turnR();
//  }
//  halt();
//  
//}

void ccturnonblack(){
  pinMode(REFLSENSOR, INPUT);
  while(analogRead(REFLSENSOR-14) > 300){
    motorControl(60,120);
    gcloop();
    //calcDist();
  }
  halt();
  
}

void ccturnonwhite(){
  pinMode(REFLSENSOR, INPUT);
  while(analogRead(REFLSENSOR-14) < 300){
     motorControl(120,60);
     gcloop();
     //calcDist();
  }
  halt();
  
}

////void avoidCrash(){
//   if (durationIn < 10);
//   {
//    while (true){
//     while(analogRead(REFLSENSOR-14) > 300){ //reverse on black
//       revControl(60,120);
//       gcloop();
//       calcDist();
//      } 
//     halt();
//     while(analogRead(REFLSENSOR-14) < 300){ //reverse on white
//      revControl(120,60);
//      gcloop();
//      calcDist();
//      }
//     halt();
//    }
//   }
//} 

