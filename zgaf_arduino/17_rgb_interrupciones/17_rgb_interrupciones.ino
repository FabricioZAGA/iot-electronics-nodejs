unsigned int count = 0; bool b_serial = false;

const unsigned char RED= 9;

const unsigned char GREEN= 7;

const unsigned char BLUE= 8;

const unsigned char RGB[] = {RED, GREEN, BLUE};
void setup() {
// put your setup code here, to run once: 
pinMode(2, INPUT_PULLUP); 
pinMode(3, INPUT_PULLUP);
for (unsigned char i = 0; i < sizeof(RGB); i++) { pinMode(RGB[i], OUTPUT);
}
  
attachInterrupt(digitalPinToInterrupt(2), incremento, RISING); attachInterrupt(digitalPinToInterrupt(3), decremento, RISING);
Serial.begin(9600); }
void ledsEval(unsigned char _count) { switch(_count) {
case 0:
digitalWrite(RED, LOW);
digitalWrite(GREEN, LOW);
digitalWrite(BLUE, LOW);
break;
case 1:
digitalWrite(RED, HIGH); 
digitalWrite(GREEN, LOW); 
digitalWrite(BLUE, LOW);
break;
case 2:
digitalWrite(RED, LOW); 
digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, LOW);
break; 
case 3:
digitalWrite(RED, LOW);
digitalWrite(GREEN, LOW); 
digitalWrite(BLUE, HIGH);
break; 
case 4:
digitalWrite(RED, HIGH);
digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, LOW);
break;
case 5:
digitalWrite(RED, HIGH);
digitalWrite(GREEN, LOW);
digitalWrite(BLUE, HIGH);
break;
case 6:
digitalWrite(RED, LOW); 
digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, HIGH);
break; 
case 7:
digitalWrite(RED, HIGH);
digitalWrite(GREEN, HIGH); 
digitalWrite(BLUE, HIGH);
break; 
default:
break;
} }
void loop() {
// put your main code here, to run repeatedly:
if (b_serial) {
b_serial = false; Serial.println(count); ledsEval(count);

} }
void incremento() { count++;
if (count > 7) { count = 0;
}
b_serial = true; }
void decremento() { count--;
if (count == 0) { count = 7;
}
b_serial = true; }
