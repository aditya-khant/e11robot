// credits to Yaqub :))
int LED1 = 13; //Inside
int LED2 = 5; //Outside
boolean invertBits = false;
boolean goldCodes[9][31] = {{0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,1,0,0,0,0,1,1,0,0,1,1,1,0,0,1,1}, 
                           {1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,1,0,0}, 
                           {0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,1,1,0},
                           {1,0,1,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,1,1,1,0,1}, 
                           {0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,1,1,0,1,0,0,1,1,1}, 
                           {1,1,1,0,0,0,1,0,0,1,1,0,1,1,1,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0}, 
                           {0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,0}, 
                           {1,0,0,1,0,1,1,1,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,0,0,1,0,0,0,1,1},
                           {0,0,0,1,0,0,1,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,1}};
void gcsetup(){
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  //pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  //delay(1500);
  invertBits = !(digitalRead(3));
  if (clockwise == true){
    int LED1 = 5; //switch them, so that the right leds flash the right code
    int LED2 = 13; 
  }
}

void gcloop() { 
  if (invertBits == false){
    for(int i=4; i<8; i++)
    { 
      for(int y=0; y<2; y++) //loops gc twice
      {
        for(int z=0; z<31; z++)
        {
            long startTime = micros();
            while(micros() - startTime <= 250)
            {
             if (goldCodes[i][z] == 1) 
                  {
                    digitalWrite(LED1, HIGH);
                    if (goldCodes[8][z] == 1){
                      digitalWrite(LED2, HIGH);
                    }
                    else{
                      digitalWrite(LED2, LOW);
                    }
                  }
             else
                  {
                    digitalWrite(LED1, LOW);
                    if (goldCodes[8][z] == 1){
                      digitalWrite(LED2, HIGH);
                    }
                    else{
                      digitalWrite(LED2, LOW);
                    }
                  }
            }
          }
      }
    }
  }

  else{
    for(int i=4; i<8; i++)
    {
      for(int y=0; y<2; y++) //loops gc twice
      {
        for(int z=0; z<31; z++)
        {
            long startTime = micros();
            while(micros() - startTime <= 250)
            {
             if (goldCodes[i][z] == 1) 
                  {
                    digitalWrite(LED1, LOW);
                    if (goldCodes[8][z] == 1){
                      digitalWrite(LED2, LOW);
                    }
                    else{
                      digitalWrite(LED2, HIGH);
                    }
                  }
             else
                  {
                    digitalWrite(LED1, HIGH);
                    if (goldCodes[8][z] == 1){
                      digitalWrite(LED2, LOW);
                    }
                    else{
                      digitalWrite(LED2, HIGH);
                    }
                  }
            }
          }
        }
      }
  }
}
