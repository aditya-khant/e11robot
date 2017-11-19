// Name: Aditya Khant . Worked with Daphne Poon

#define PHOTSENSOR 19
#define sampLength 31
#define gcLen 31
#define lengthGoldCodes 31
#define numGoldCodes 9

//initialize all variables
unsigned long sampleStart = 0;
int lastdigit = 0;
int rawSamples[sampLength] = {0, 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 0, 0};
int mainSamples[sampLength] = {0, 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 0, 0};
int WGC[numGoldCodes][sampLength] =
{ {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1},
  {1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
  {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0},
  {1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1},
  {0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1}
};
int returnVal[2] = {0, 0};

int d[sampLength];
int e[sampLength];
int b[sampLength];
int c[sampLength];
int arrayw[numGoldCodes];
int D1, D2;
int lastdigit1, lastdigit2;
int tempWGC[sampLength];
char color = 'w';

int goldCodes[numGoldCodes][gcLen];
int goldcTemp[gcLen];



boolean detectGoldCode() {
  //run all functions
  sampleCollect();
  toBinary();
  correlateR();
  //pnt();
  if (abs(D1) > 30 and D2 < 5) {
    if (color == 'w') {
      if (isWhite) {
        return false;
      } else {
        return true;
      }
    } else if (color == 'g') {
      if (isWhite) {
        return true;
      } else {
        return false;
      }
    } else {
      return false;
    }
  } else {
    return false;
  }
}

void sampleCollect() {
  int i = 0; //initialize counter
  sampleStart = micros(); // initialize start time
  while ( i < sampLength) { //loop until i < 31
    if (micros() - sampleStart > 250 * i ) { // tries to find intervals of time that are multiples of 250
      rawSamples[i] = analogRead(PHOTSENSOR); //stores the value of the photosensor in raw Samples
      i++; //increase the counter

    }
  }


}

void toBinary() { //convert the raw values to binary
  //initialize variables
  int average = 0;
  int sum = 0;
  //find the sum
  for (int i = 0; i < sampLength ; i++) {
    sum += rawSamples[i];
  }
  //find the average
  average = sum / (sampLength );
  //if value is below average, set it to 1, else, set it to 0
  for (int i = 0; i < sampLength ; i++) {
    if (rawSamples[i] < average) {
      mainSamples[i] = 1;
    } else {
      mainSamples[i] = 0;
    }

  }
}

void correlateR()
{
  // this takes g and finds the gold code of index g and correlates it with m
  for (int g = 0; g < numGoldCodes; g++)
  {
    for (int i = 0; i < sampLength; i++) // copies gold codes into arrays tempGC and b.
    {
      tempWGC[i] = WGC[g][i];
      b[i] = mainSamples[i];
    }

    for (int i = 0; i < sampLength; i++)
      // run shift() through 31 times.
      // also prints the correlated value each time.
    {
      // sets up an array that is the correlated version of b and tempGC, with tempGC being shifted 31 times.
      d[i] = correlate(b, tempWGC);
      shift();
    }

    // sets the maximum correlated value forcolors with the maximum aboslute value
    arrayw[g] = maximum2(d, sampLength);

  }
  maximum(arrayw, numGoldCodes);
  D1 = returnVal[0] ; // Get the correlation value
  D2 = returnVal[1] + 1; // Get the ID

  if (D1 < 0) { // set the color to green if the value is negative, else set the color to positive
    color = 'g';
  } else {
    color = 'w';
  }

}

void pnt() {
  //Print out all the relevant values
  Serial.print("ID Number: ");
  Serial.println(D2);
  Serial.print("The corresponding correlation: ");
  Serial.println(D1);
  Serial.print("Team color: ");
  //If the color is w print "White" else print "Green"
  if (color == 'w') {
    Serial.println("WHITE");
  }
  else if (color == 'g') {
    Serial.println("GREEN");
  }
  else {
    Serial.println("something went wrong");
  }

}

void shift()
{
  //takes the last digit of the array and saves it
  lastdigit1 = tempWGC[sampLength - 1];

  // shifts everything in the sequence one right
  for (int q = (sampLength - 1); q >= 0; q--)
  {
    tempWGC[q] = tempWGC[q - 1];

  }
  // takes the saved digit and moves it to the first index
  tempWGC[0] = lastdigit1;

}

// takes 2 arrays and correlates them, and then outputs the dot product
int correlate(int j[sampLength], int k[sampLength])
{
  //defines two variables
  // i is iterated
  // val is the value (dot product) which is the sum of all the ...
  // ... dot products of each index under j[i] and k[i]
  int i = 0;
  int val = 0;
  while (i < sampLength) // iterating i 31 times to correlate
  {
    if (j[i] != k[i]) // if the one value DOES NOT equal the other value
    {
      val = val - 1 ; // take away one point
    }
    else // if it does
    {
      val = val + 1 ; // add a point
    }
    i++;
  }

  return val;
}

void maximum(int x[], int y) //finds the value of d with maximum absolute value
{
  // defines variable maxx
  int maxx = 0;
  // loops a

  for (int a = 0; a < y; a++)
  {
    if (abs(x[a]) > abs(maxx)) {
      maxx = x[a];
      returnVal[0] = x[a]; // if it's bigger than the stored maximum value, replace maxx with x[a]
      returnVal[1] = a;
    }

  }

}

int maximum2(int x[], int y) //finds the value of d with maximum absolute value
{
  // defines variable maxx
  int maxx = 0;
  int returnthis = 0;
  // loops a

  for (int a = 0; a < y; a++)
  {
    if (abs(x[a]) > abs(maxx)) {
      maxx = x[a]; // if it's bigger than the stored maximum value, replace maxx with x[a]
      returnthis = a;
    }

  }
  return maxx;
}

void returnStrat() {
  if (millis() - whendidwestart > returnTime) {

    if (!isWhite) {
      if (D2 == 2 ) {
        
        while (true) {
          halt();
        }
      }

    } else {
      if (D2 == 4 ) {
        while (true) {
          halt();
        }
      }
    }
  }

}
