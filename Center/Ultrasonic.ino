//#define trigpin 10
//#define echopin 2
//
//void initUS(){
//  pinMode(trigpin, OUTPUT);
//  pinMode(echopin, INPUT);
//}
//
//
//float calcDist(){
//  float cmVal = 1.0;
//  float cmCon = (340.0/10000.0)/2.0;
//  float inCon = (1.0/2.54);
//  int durationIn = 1;
//  digitalWrite(trigpin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigpin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigpin, LOW);
//  durationIn = pulseIn(echopin, HIGH, 50000);
//  cmVal = cmCon * durationIn;
//  //inchVal = cmVal * inCon;
//  Serial.print("Distance in cm: ");
//  Serial.println(durationIn);
//  return cmVal;
//  //Serial.print("Distance in inch: ");
//  //Serial.println(inchVal);
//}
