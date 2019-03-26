void setup() {
  #include <avr/io.h>
  // put your setup code here, to run once:


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

}
