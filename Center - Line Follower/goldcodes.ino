// credits to Yaqub :))
#define LED1 13 //Inside
#define LED2 5 //Outside
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
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(1500);
  invertBits = !(digitalRead(3));
}

void gcloop() { 
  if (invertBits == false){
    for(int i=4; i<8; i++)
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
  else{
    for(int i=4; i<8; i++)
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