unsigned char leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
unsigned char count = 0;

void setup() {
  // put your setup code here, to run once:
    for(char i = 0; i < sizeof(leds); i++ ) {
     pinMode(leds[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(char i = sizeof(leds); i >= 0; i-- ) {
    digitalWrite(leds[i], HIGH);
    delay(300);
  }
  for(char i = 0; i < sizeof(leds); i++ ) {
    digitalWrite(leds[i], LOW);
    delay(300);
  }
}
