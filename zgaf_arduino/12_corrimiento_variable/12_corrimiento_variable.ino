unsigned char outputs[] = {2, 3, 4, 5, 6, 7, 8, 9};
unsigned char inputs[] = {10, 11, 12, 13};
unsigned int number = 0;
unsigned int count = 0;


void setup() {
  // put your setup code here, to run once:
  for (unsigned int i = 0; i < sizeof(outputs); i++) {
    pinMode(outputs[i], OUTPUT);
  }

  for (unsigned int i = 0; i < sizeof(inputs); i++) {
    pinMode(inputs[i], INPUT_PULLUP);
  }

  Serial.begin(9600); // open the serial port at 9600 bps:
}

void convertBinToDec() {
  int ReturnInt = 0;
  
  for (int i = 0; i < sizeof(inputs); i++) {
    if(digitalRead(inputs[i]) == LOW) {
      if (inputs[sizeof(inputs) - i]) {
        ReturnInt += 1<<i;
      }
    }
  }
  Serial.print(ReturnInt);
  number = ReturnInt;
}

void loop() {
  // put your main code here, to run repeatedly:
  convertBinToDec();
  
  delay(100 - number * 6.25);

  for(char i = 0; i < sizeof(outputs); i++ ) {
    if (number == 0) {
      digitalWrite(outputs[i], LOW);
    } else {
      if (count == i) {
        digitalWrite(outputs[i], HIGH);
      } else {
        digitalWrite(outputs[i], LOW);
      }
    }
  }
  
  if (count == sizeof(outputs)) {
    count = 0;
  } else {
    count++;
  }
}
