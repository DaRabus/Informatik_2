/*****************************
   * Rabus *
   * HTW CHUR *
   * 25. FEB 2019 *
   * Poti LED-Stair *
  ******************************/
#include <Bounce2.h>
#include <avr/io.h>
#include <ResponsiveAnalogRead.h>



int potPin = 0; //Potentioneter Pin
int ledPins[] = {8, 9, 10, 11};
int inPin = 12; // Button Input
int ledState = LOW;

ResponsiveAnalogRead analog(potPin, true);
Bounce debouncer = Bounce(); // Instantiate a Bounce object

void setup() {

  
  Serial.begin(115200); //Monitoring

  
debouncer.attach(inPin,INPUT_PULLUP); //Debouncing pins
debouncer.interval(25); // Use a debounce interval of 25 milliseconds
  for (byte i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT); //set pins as output
    digitalWrite(ledPins[i],ledState); //activate pins
  } 
         

 
  /*
    ledState = !ledState; // Toggle LED state
    for (byte i = 0; i < 4; i++) {
      digitalWrite(ledPins[i],ledState);
      }
      ledState = !ledState; // Toggle LED state
    for (byte i = 0; i < 4; i++) {
      digitalWrite(ledPins[i],ledState);
      }
*/


}


void loop() {
  // put your main code here, to run repeatedly:
debouncer.update(); // Update the Bounce instance
if ( debouncer.fell() ) { //Take timestamp for Button pressed
  ledState = !ledState; // Toggle LED state
    for (byte i = 0; i < 4; i++) {
      digitalWrite(ledPins[i],ledState);
      }
    }
analog.update(); //Debounce Analog Signal
    
Serial.println(analog.getValue());          // debug value

}

    
