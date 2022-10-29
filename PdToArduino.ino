//////////////////////////////////////
// PdToArduino1
// for basic communication with Pure Data (Pd)
// NOTE: all the data sent to Pd uses Serial.println()
//
// Jiffer Harriman
// These files are licensed under a Creative Commons Attribution Share-Alike license
// modular-muse.com
//////////////////////////////////////

// for incoming serial data; Expecting 3 values every time
// change this to match the number of bytes you are sending from Pd
#define NUMBYTES 9 // number of bytes  sent by Pd in a "packet"

int incomingByte[NUMBYTES]; 

int numOutputs;

int outputPins[] = {3, 5, 13}; // PWM outputs: pins 3, 5 and 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  numOutputs = sizeof(outputPins) / sizeof(int);
  
  // initialize output pins
  for (int i = 0; i < numOutputs; i++)
  {
    pinMode(outputPins[i], OUTPUT);
  }

}

// main loop
void loop() {

  /////////////////////
  // read from Pd
  /////////////////////
  // Check if we've collected new data from Pd
  // Here it looks for 2 values, the first is the output port
  // the second is the new value to write to that output
  /*
    if (Serial.available() > 1) {
  
      for ( int i = 0; i < 2; i++) {
        incomingByte[i] = Serial.read();
      }
      analogWrite(outputPins[incomingByte[0]], incomingByte[1]);
    }*/

  int id, x, y, t1, t2;
  // look for 3 bytes of data and write them to the 3 output pins
  if (Serial.available() > NUMBYTES-1) {
    for ( int i = 0; i < NUMBYTES; i++) {
      incomingByte[i] = Serial.read();
    }
    id = incomingByte[0];
    x = incomingByte[1]*255 + incomingByte[2];
    y = incomingByte[3]*255 + incomingByte[4];
    
    if (x == 1534) { 
      Serial.println("0");
      digitalWrite(13, HIGH);
      delay(100);
    }
    else analogWrite(13, LOW);
  }

  // short break
  delay(10);
}
