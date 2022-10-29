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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
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
    t1 = incomingByte[5]*255 + incomingByte[6];
    t2 = incomingByte[7]*255 + incomingByte[8];
//    Serial.println("%d %d %d %d %d %d %d %d %d %d", incomingByte[0], incomingByte[1], incomingByte[2], incomingByte[3], incomingByte[4], incomingByte[5], incomingByte[6], incomingByte[7], incomingByte[8]);
 //   Serial.print("id = ");
    Serial.print(id);  Serial.print(" ");
 //   Serial.print(" x = ");
    Serial.print(x); Serial.print(" ");
 //   Serial.print(" y = ");
    Serial.print(y); Serial.print(" ");
 //   Serial.print(" t1 = ");
    Serial.print(t1); Serial.print(" ");
 //   Serial.print(" t2 = ");
    Serial.println(t2); 
  }

  // short break
  delay(5);
}
