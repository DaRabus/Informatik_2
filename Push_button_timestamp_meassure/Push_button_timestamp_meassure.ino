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


void setup() { // put your setup code here, to run once:
   Serial.begin(9600); //Serial Monitor Start
   debouncer.attach(inPin,INPUT_PULLUP); //Debouncing
   debouncer.interval(25); // Use a debounce interval of 25 milliseconds
  //Declaring the pins as a Output
  for (byte i = 0; i < 4; i++) {
  pinMode(ledPins[i], OUTPUT);
  digitalWrite(ledPins[i],ledState);
  }

}

void loop() {

   

   debouncer.update(); // Update the Bounce instance

   int time_start, time_end, time_tot;
   
   if ( debouncer.fell() ) {  // Call code if button transitions from HIGH to LOW
      ledState = !ledState; // Toggle LED state
      for (byte i = 0; i < 4; i++) {
      digitalWrite(ledPins[i],ledState);
  } // Apply new LED state
     time_start = millis();
     Serial.println("Taste ist gedrueckt"); 
   }
   
   if ( debouncer.rose() ) {  // Call code if button transitions from LOW to HIGH
     time_end = millis();
     time_tot=time_end-time_start;
     Serial.print(time_tot); Serial.println("\n"); 
     ledState = !ledState; // Toggle LED state
      for (byte i = 0; i < 4; i++) {
      digitalWrite(ledPins[i],ledState);}
   }
    
}
