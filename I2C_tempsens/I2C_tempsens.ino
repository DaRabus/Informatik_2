#include <avr/io.h>
#include <Wire.h> //for I2C Communicaton

int tempadr = 0x48; // Device address in which is also included the 8th bit for selecting the mode, read in this case.
int tempnow;

void setup() {
 Wire.begin(); // Initiate the Wire library
 Serial.begin(115200); // start serial for output

 /*Wire.beginTransmission(tempadr); //begin Transmission
  Wire.write(01h); //config register
  Wire.write(0B01100000); //10Conv/s rest standard
    Wire.endTransmission();
*/
}


void loop() {


Wire.requestFrom(tempadr,2);

  while(Wire.available())    // slave may send less than requested
  { 
    int MS = Wire.read();    // read LSByte
    int LS = Wire.read();    // read MSByte

    int temp = ((MS <<8) | LS)>>3; // combine the two Bytes
    float temp_f = temp * 0.03125;
    Serial.println(temp_f);         // print the character
}

}
