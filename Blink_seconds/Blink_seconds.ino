/*****************************
   * Rabus *
   * HTW CHUR *
   * 25. FEB 2019 *
   * Poti LED-Stair *
  ******************************/
#include <Bounce2.h>

//Global Variables:

// The pins to which we've wired each of the LEDs
int ledPins[] = {8, 9, 10, 11};
int inPin = 12; // Button Input
int ledState = LOW;

Bounce debouncer = Bounce(); // Instantiate a Bounce object


void setup() {
   Serial.begin(9600); 
  // put your setup code here, to run once:
  debouncer.attach(inPin,INPUT_PULLUP);
  debouncer.interval(25); // Use a debounce interval of 25 milliseconds
  //Declaring the pins as a Output
  for (byte i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i],ledState);
  }

   

}

void loop() {

   unsigned long time_start; 
   unsigned long time_now; 
   long intervall = 1000; 

   debouncer.update(); // Update the Bounce instance
   time_start = millis();

   if ( debouncer.fell() ) {
    time_now=millis();
    }
   
   if(time_start-time_now == intervall){
      ledState = !ledState; // Toggle LED state
      for (byte i = 0; i < 4; i++) {
      digitalWrite(ledPins[i],ledState);
      }
      delay(20);
      ledState = !ledState; // Toggle LED state
      for (byte i = 0; i < 4; i++) {
      digitalWrite(ledPins[i],ledState);
      }
   }
   }

   
