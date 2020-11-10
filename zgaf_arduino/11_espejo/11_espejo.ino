unsigned char outputs[] = {2, 3, 4, 5, 6, 7, 8, 9};
unsigned char inputs[] = {10, 11, 12, 13, A0, A1, A2, A3};

void setup() {
  // put your setup code here, to run once:
  for (unsigned int i = 0; i < sizeof(outputs); i++) {
    pinMode(outputs[i], OUTPUT);
  }

  for (unsigned int i = 0; i < sizeof(inputs); i++) {
    pinMode(inputs[i], INPUT_PULLUP);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  for (unsigned char i = 0; i < sizeof(outputs); i++) {
    digitalWrite(outputs[i], !digitalRead(inputs[i]));
  }

}
