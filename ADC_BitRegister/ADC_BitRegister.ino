/*****************************
   * Rabus *
   * HTW CHUR *
   * 25. FEB 2019 *
   * Poti LED-Stair *
  ******************************/
#include <Bounce2.h>
#include <avr/io.h>



int potPin = 0; //Potentioneter Pin

//Code for Blinking ledS
int ledPins[] = {8, 9, 10, 11};
int inPin = 12; // Button Input
int ledState = LOW;
int outputconsole;

Bounce debouncer = Bounce(); // Instantiate a Bounce object

void setup() {
 Serial.begin(115200); //Monitoring

ADMUX = 0B01000000; //Adlar = 0, 
ADCL =  0B00000001; //ADC0 as Input pin
ADCSRA = 0B10000111; //ADC enable , ADC Start Conversation , 128bit prescale

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



   //Start ADC Conversation
   ADCSRA = 0B11000111;   


while(ADCSRA & 0B01000000){ //Wait for finishing conversation
}

outputconsole = ADCL | (ADCH <<8); //Move Bit 8 positions to fill 10bit safe
Serial.println(outputconsole); 
}

    
