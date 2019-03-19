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
TCCR1B = 0;
OCR1A = 16000;
TCCR1B |= (1 << CS12);    // 256 als Prescale-Wert spezifizieren
TIMSK1 |= (1 << TOIE1);   // Timer Overflow Interrupt aktivieren
interrupts();             // alle Interrupts scharf schalten


Serial.println("Register TCCR1A:");Serial.println(TCCR1A);
Serial.println("Register TCCR1B:");Serial.println(TCCR1B);
Serial.println("Register TCCR1C:");Serial.println(TCCR1C);
Serial.println("Register TCNT1L:");Serial.println(TCNT1L);
Serial.println("Register OCR1AH:");Serial.println(OCR1AH);
Serial.println("Register OCR1AL:");Serial.println(OCR1AL);
Serial.println("Register OCR1A:");Serial.println(OCR1A);
Serial.println("Register OCR1BH:");Serial.println(OCR1BH);
Serial.println("Register OCR1BL:");Serial.println(OCR1BL);
Serial.println("Register ICR1H:");Serial.println(ICR1H);
Serial.println("Register TIMSK1:");Serial.println(TIMSK1);
Serial.println("Register TIFR1:");Serial.println(TIFR1);




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

    
}

ISR(TIMER1_OVF_vect)  {
  OCR1A = 16000;
  ledState = !ledState; // Toggle LED state
    for (byte i = 0; i < 4; i++) {
      digitalWrite(ledPins[i],ledState);
      }
      ledState = !ledState; // Toggle LED state
    for (byte i = 0; i < 4; i++) {
      digitalWrite(ledPins[i],ledState);
      }
  }
