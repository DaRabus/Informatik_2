/*****************************
   * Marc Schaufelberger *
   * HTW CHUR *
   * 25. FEB 2019 *
   * Poti LED-Stair *
  ******************************/

int potPin = 0; // select the input pin for the potentiometer 
int led1 = 11;// the pin the LED is connected to
int led2 = 10;
int led3 = 9;
int led4 = 8;
int val = 0;       // variable to store the value coming from the sensor

void setup() {
    pinMode(13, OUTPUT); //onboard LED
    pinMode(led1, OUTPUT);// Declare the LED as an output
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

void loop() {
  
  val = analogRead(potPin);    // read the value from the sensor
  delay(1000);              
  digitalWrite(13, LOW);  //set onboard LED LOW
  delay(1000);   
  digitalWrite(led4, HIGH);
  delay(1000); 
  digitalWrite(led3, HIGH); 
  delay(1000);  
  digitalWrite(led2, HIGH);
  delay(1000);  
  digitalWrite(led1, HIGH);
  delay(1000);  


}
