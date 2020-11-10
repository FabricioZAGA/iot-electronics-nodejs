#include <IRremote.h>

unsigned char Rojo = 7;
unsigned char Verde = 6;
unsigned char Azul = 5;
unsigned char secuencia = 0;
unsigned int velocidad = 300;
unsigned int color = 0;

unsigned char infrarrojo = 13;
IRrecv ir(infrarrojo);
decode_results code;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(Rojo, OUTPUT);
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);
  ir.enableIRIn();
  
}

void ControlRemoteDecoder(unsigned int codigo) {
  switch(codigo) {
    case 0xFFA25D:
    if(velocidad < 1000) {
      velocidad = velocidad + 100;
    }
    Serial.println("CH-");
    break;
    case 0xFF629D:
    secuencia = 1;
    Serial.println("CH");
    break;
    case 0xFFE21D:
    if(velocidad > 0) {
      velocidad = velocidad - 100;
    }
    Serial.println("CH+");
    break;
    case 0xFF6897:
    secuencia = 0;
    digitalWrite(Rojo,LOW);
    digitalWrite(Verde,LOW);
    digitalWrite(Azul,LOW);
    Serial.println("0");
    break;
    case 0xFF30CF:
    secuencia = 0;
    digitalWrite(Rojo,HIGH);
    digitalWrite(Verde,LOW);
    digitalWrite(Azul,LOW);
    Serial.println("1");
    break;
    case 0xFF18E7:
    secuencia = 0;
    digitalWrite(Rojo,LOW);
    digitalWrite(Verde,HIGH);
    digitalWrite(Azul,LOW);
    Serial.println("2");
    break;
    case 0xFF7A85:
    secuencia = 0;
    digitalWrite(Rojo,LOW);
    digitalWrite(Verde,LOW);
    digitalWrite(Azul,HIGH);
    Serial.println("3");
    break;
    case 0xFF10EF:
    secuencia = 0;
    digitalWrite(Rojo,HIGH);
    digitalWrite(Verde,HIGH);
    digitalWrite(Azul,LOW);
    Serial.println("4");
    break;
    case 0xFF38C7:
    secuencia = 0;
    digitalWrite(Rojo,LOW);
    digitalWrite(Verde,HIGH);
    digitalWrite(Azul,HIGH);
    Serial.println("5");
    break;
    case 0xFF5AA5:
    secuencia = 0;
    digitalWrite(Rojo,HIGH);
    digitalWrite(Verde,LOW);
    digitalWrite(Azul,HIGH);
    Serial.println("6");
    break;
    case 0xFF42BD:
    secuencia = 0;
    digitalWrite(Rojo,HIGH);
    digitalWrite(Verde,HIGH);
    digitalWrite(Azul,HIGH);
    Serial.println("7");
    break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ir.decode(&code)) {
    // Serial.println(code.value, HEX);
    ControlRemoteDecoder(code.value);
    ir.resume();
    //delay(300);
  }
  if (secuencia == 1) {
    switch(color){
      case 0:
    digitalWrite(Rojo,LOW);
    digitalWrite(Verde,LOW);
    digitalWrite(Azul,LOW);
    break;
    case 1:
    digitalWrite(Rojo,HIGH);
    digitalWrite(Verde,LOW);
    digitalWrite(Azul,LOW);
    break;
    case 2:
    digitalWrite(Rojo,LOW);
    digitalWrite(Verde,HIGH);
    digitalWrite(Azul,LOW);
    break;
    case 3:
    digitalWrite(Rojo,LOW);
    digitalWrite(Verde,LOW);
    digitalWrite(Azul,HIGH);
    break;
    case 4:
    digitalWrite(Rojo,HIGH);
    digitalWrite(Verde,HIGH);
    digitalWrite(Azul,LOW);
    break;
    case 5:
    digitalWrite(Rojo,LOW);
    digitalWrite(Verde,HIGH);
    digitalWrite(Azul,HIGH);
    break;
    case 6:
    digitalWrite(Rojo,HIGH);
    digitalWrite(Verde,LOW);
    digitalWrite(Azul,HIGH);
    break;
    case 7:
    digitalWrite(Rojo,HIGH);
    digitalWrite(Verde,HIGH);
    digitalWrite(Azul,HIGH);
    break;
    }
    if (color == 7) {
      color = 0;
    }
    else {
      color++;
    }
    delay(velocidad);
  }
}
