/*****************************
   * Rabus *
   * HTW CHUR *
   * 25. FEB 2019 *
   * Poti LED-Stair *
  ******************************/
#include <Bounce2.h>
#include <avr/io.h>

int ledPins[] = {8, 9, 10, 11};
int inPin = 12; // Button Input
int ledState = LOW;
int ms = 0;
int s;
int mint;
Bounce debouncer = Bounce(); // Instantiate a Bounce object

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
debouncer.attach(inPin,INPUT_PULLUP);
debouncer.interval(25); // Use a debounce interval of 25 milliseconds
  for (byte i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i],ledState);
  }

noInterrupts();           // Alle Interrupts temporär abschalten
 TCCR1A = 0;
OCR1A = 16000;
TCCR1B = 0B00001001;       // CS00 als 1 als Prescale-Wert spezifizieren und WGM02 aktivieren
TIMSK1 = 0B00000010; // Timer Compare Interrupt aktivieren
interrupts();             // alle Interrupts scharf schalten

 
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
ISR(TIMER1_COMPA_vect)  {
   ms++;
  if(ms==1000){
    ms = 0;
    s++;
  }
   if(s==60){
    s=0;
    mint++;
   }
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

Serial.println(String(mint) + " Minuten " + String(s) + " Sekunden " + String(ms) + "  Millisekunden");

}

    
