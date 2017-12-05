#define boopPin 13 //Pin to read the bump sensor value
#define boopOut 5 //Pin to send current to bump sensor
#define returnTime 50000 // Time in ms to return back to base

// Initialization of global variabkes
int x = 0; 
int m = 0;
bool isWhite = true;
long whendidwestart = millis();

void setup() {
  // put your setup code here, to run once:
  long startTime = millis(); // Set starttime for gold code detection
  bool letsReturn = false; //To return or not to return
  Serial.begin(9600); // initialize Serial
  //Initializes pins
  pinMode(3, INPUT); 
  pinMode(boopPin, INPUT);
  pinMode(boopOut, OUTPUT);
  digitalWrite(boopOut, HIGH);
  whendidwestart = millis(); 
  isWhite = digitalRead(3); //Checks if team is green actually because the LEDs were wired reversely
  initMotors(); //Initializes motor pins
  //initUS();
  setupMove(); //Moves forward and then turns right


}

void loop() {
  workingWithReturn(); // Main function that worked with return
  
}

void workingWithoutReturn(){// Main function without returning
  
  while (!(detectGoldCode()) and !(digitalRead(boopPin))) { //While it didnt detect a gold code or didnt bump into anything
    motorControl(255, 240); // Go almost straight slightly towards the right
  }
  if (detectGoldCode() ) { // If it detects a gold code claimed by us
    runAway(); // Turn away 
  }
  if (digitalRead(boopPin)) { //If it bumps into something 
    halt(); //stop
    while (digitalRead(boopPin)) { //while its bumped
      motorControl(255, -255); //turn about a point with full power.
      delay(400);
    }
  }
  
}


void workingWithReturn(){
  
  while (!(detectGoldCode()) and !(digitalRead(boopPin))) {//While it didnt detect a gold code or didnt bump into anything
    
    motorControl(255, 240); // Go almost straight slightly towards the right
    returnStrat(); // try returning back to base
    
  }
  if (detectGoldCode() ) {// If it detects a gold code claimed by us
    
    returnStrat(); // try returning back to base
    runAway(); // Turn away 
  }
  if (digitalRead(boopPin)) { //If it bumps into something 
    halt(); // stop
    while (digitalRead(boopPin)) { //while its bumped
      motorControl(255, -255); //turn about a point with full power.
      delay(400);
    }
  }

}



