/*****************************
   * Rabus *
   * HTW CHUR *
   * 25. FEB 2019 *
   * ADC_BitRegister *
  ******************************/
#include <Bounce2.h>
#include <avr/io.h>




//Code for Blinking ledS
int ledPins[] = {8, 9, 10, 11};
int inPin = 12; // Button Input
int ledState = LOW;

int interruptPin = 0; //Interrupt Pin in this case the Potentiometer

Bounce debouncer = Bounce(); // Instantiate a Bounce object

void setup() {
 Serial.begin(115200); //Monitoring

 pinMode(interruptPin, INPUT_PULLUP); //Set poti as pullup
 attachInterrupt(digitalPinToInterrupt(interruptPin), myISR, FALLING); //activate Interrupt on poti

  DDRD = DDRD & B11110111;
  PORTD = PORTD | B00001000;

  EICRA = EICRA | B00001000;
  EIMSK = EIMSK | B00000010;
  

//Code for Blinking ledS  
debouncer.attach(inPin,INPUT_PULLUP); //Debouncing pins
debouncer.interval(25); // Use a debounce interval of 25 milliseconds
  for (byte i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT); //set pins as output
    digitalWrite(ledPins[i],ledState); //activate pins
  } 
         

}


void loop() {
//Code for Blinking ledS
debouncer.update(); // Update the Bounce instance
if ( debouncer.fell() ) { //Take timestamp for Button pressed
  ledState = !ledState; // Toggle LED state
    for (byte i = 0; i < 4; i++) {
      digitalWrite(ledPins[i],ledState);
      }
    }
}

void myISR() {

  // Output the duty cycle to the serial monitor
  Serial.println("Interrupt wurde ausgelöst!!");
}

    
