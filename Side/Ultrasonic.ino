//ULTRASONIC SENSOR CODE - WE DIDNT USE THIS BECAUSE IT DIDNT WORK

//Initialize pins
#define trigpin 5
#define echopin 10

void initUS(){
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}


float calcDist(){
  //Initial Variables
  float cmVal = 1.0;
  float cmCon = (340.0/10000.0)/2.0;
  float inCon = (1.0/2.54);
  int durationIn = 1;
  //First write low and then write High after 2 microseconds
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  //use pulsein to get a reading
  durationIn = pulseIn(echopin, HIGH, 50000);
  //convert reading to cm
  cmVal = cmCon * durationIn;
  //inchVal = cmVal * inCon;
  // Serial.print("Distance in cm: ");
  Serial.println(durationIn);
  return cmVal;
  //Serial.print("Distance in inch: ");
  //Serial.println(inchVal);
}
