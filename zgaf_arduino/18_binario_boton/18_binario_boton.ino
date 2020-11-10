const unsigned char a = 13;
const unsigned char b = 12;
const unsigned char c = 11;
const unsigned char d = 10;
const unsigned char e = 9;
const unsigned char f = 8;
const unsigned char g = 7;

const unsigned char displaySeg[] = {a,b,c,d,e,f,g};

unsigned char count = 0;
bool b_serial = false;
void setup() {
// put your setup code here, to run once: 
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);
  

 for(unsigned char i = 0;i<sizeof(displaySeg);i++){
    pinMode(displaySeg[i],OUTPUT);
  }

attachInterrupt(digitalPinToInterrupt(2), incremento, FALLING); attachInterrupt(digitalPinToInterrupt(3), decremento, RISING);
Serial.begin(9600); }
void setLedValueEventListener(){ 
  switch(count){
case 0:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
  break;
  case 1:
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  break;
  case 2:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);
  break;
  case 3:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);
  break;
  case 4:
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
  break;
  case 5:
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
  break;
  case 6:
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
  break;
  case 7:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  break;
  case 8:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
  break;
  case 9:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
  break;
} }
void loop() {
// put your main code here, to run repeatedly:
if (b_serial) {
b_serial = false; Serial.println(count);

setLedValueEventListener(); }
}
void incremento() { count++;
if (count > 9) { count = 0;
}
b_serial = true; }
void decremento() { count--;
if (count < 0) { count = 9;
}
b_serial = true; }
