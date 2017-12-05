
int LED1 = 13; //Inside
int LED2 = 5; //Outside
boolean invertBits = false; //we define invertBits, which is false by default
// hard-coding the gold codes
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
  pinMode(3, INPUT);
  pinMode(LED1, OUTPUT); //initializes the pin for the inside LEDs
  pinMode(LED2, OUTPUT); //initializes the pin for the outside LEDs
  digitalWrite(LED1, LOW); //sets all 4 LEDs as low
  digitalWrite(LED2, LOW);
  invertBits = !(digitalRead(3)); 
  // If pin 3 is low (i.e. we are on team green), set invertBits as 1.
  // Otherwise, if we are on team white, there is no need to invert the bits.
}

void gcloop() { 
  if (invertBits == false){ // if we are on team white
    for(int i=4; i<8; i++) 
    //this loops through gold codes 5,6,7,8, which are on indexes 4 through 7.
    { 
      for(int y=0; y<2; y++) //loops the gold code twice (flashing 5,5,6,6,7,7,8,8)
      {
        for(int z=0; z<31; z++) //runs through the 31 registers in one gold code
        {
            long startTime = micros(); //sets the variable startTime as the current time, in microseconds
            while(micros() - startTime <= 250) //while 250 microseconds have NOT elapsed
            {
             if (goldCodes[i][z] == 1) // if the register on the iterating code we are currently flashing is 1
                  {
                    digitalWrite(LED1, HIGH); // set the inner LED to be on high
                    if (goldCodes[8][z] == 1){ //we are constantly flashing gold code 9 (index 8) on the outside LED
                      digitalWrite(LED2, HIGH); //if the register is equal to 1, set the outside LED on high
                    }
                    else{
                      digitalWrite(LED2, LOW); //otherwise, have it be on low.
                    }
                  }
             else //this does the same thing as the above loop, except this is run when the register bit is 0.
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

  else{ // if we are on team green (this does everything the above code does, with minor differences)
    for(int i=4; i<8; i++)
    {
      for(int y=0; y<2; y++)
      {
        for(int z=0; z<31; z++)
        {
            long startTime = micros();
            while(micros() - startTime <= 250)
            {
             if (goldCodes[i][z] == 1) 
                  {
                    digitalWrite(LED1, LOW); //now, if the iterating register bit is 1, set the LED to be low instead of high
                    if (goldCodes[8][z] == 1){
                      digitalWrite(LED2, LOW); //same thing, but for the outside LED
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
