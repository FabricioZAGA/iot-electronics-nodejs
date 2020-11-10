#include <IRremote.h>

unsigned char infrarrojo = 13;
unsigned int password = 1234;
unsigned int pwd = 0;
unsigned int temporal;
IRrecv ir(infrarrojo);
decode_results code;

void ControlRemoteDecoder(unsigned int codigo) {
  switch(codigo) {
    case 0xFF906F:
    Serial.write(10);
          if(pwd == password){
            Serial.println("Password correcto");
            Serial.println("Abriendo puerta por 10 segundos");
            for (unsigned char i = 0; i < 10; i++){
              Serial.print(".......");
              Serial.println(i+1);
              delay(1000);
            }
            Serial.println("Cerrando puerta");
          }
          else {
            Serial.println("Password incorrecto");
          }
          pwd = 0;
          Serial.println("Ingresar contrasenia: ");
    break;
    case 0xFF6897:
    temporal = pwd;
    if(temporal < 9999){
      temporal *= 10;
      temporal += 0;
      if(temporal < 9999) {
        pwd = temporal;
        Serial.print("0");
      }
    }
    break;
    case 0xFF30CF:
    temporal = pwd;
    if(temporal < 9999){
      temporal *= 10;
      temporal += 1;
      if(temporal < 9999) {
        pwd = temporal;
        Serial.print("1");
      }
    }
    break;
    case 0xFF18E7:
    temporal = pwd;
    if(temporal < 9999){
      temporal *= 10;
      temporal += 2;
      if(temporal < 9999) {
        pwd = temporal;
        Serial.print("2");
      }
    }
    break;
    case 0xFF7A85:
    temporal = pwd;
    if(temporal < 9999){
      temporal *= 10;
      temporal += 3;
      if(temporal < 9999) {
        pwd = temporal;
        Serial.print("3");
      }
    }
    break;
    case 0xFF10EF:
    temporal = pwd;
    if(temporal < 9999){
      temporal *= 10;
      temporal += 4;
      if(temporal < 9999) {
        pwd = temporal;
        Serial.print("4");
      }
    }
    break;
    case 0xFF38C7:
    temporal = pwd;
    if(temporal < 9999){
      temporal *= 10;
      temporal += 5;
      if(temporal < 9999) {
        pwd = temporal;
        Serial.print("5");
      }
    }
    break;
    case 0xFF5AA5:
    temporal = pwd;
    if(temporal < 9999){
      temporal *= 10;
      temporal += 6;
      if(temporal < 9999) {
        pwd = temporal;
        Serial.print("6");
      }
    }
    break;
    case 0xFF42BD:
    temporal = pwd;
    if(temporal < 9999){
      temporal *= 10;
      temporal += 7;
      if(temporal < 9999) {
        pwd = temporal;
        Serial.print("7");
      }
    }
    break;
    case 0xFF4AB5:
    temporal = pwd;
    if(temporal < 9999){
      temporal *= 10;
      temporal += 8;
      if(temporal < 9999) {
        pwd = temporal;
        Serial.print("8");
      }
    }
    break;
    case 0xFF52AD:
    temporal = pwd;
    if(temporal < 9999){
      temporal *= 10;
      temporal += 9;
      if(temporal < 9999) {
        pwd = temporal;
        Serial.print("9");
      }
    }
    break;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ingrsar contraseña: ");
  ir.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ir.decode(&code)) {
    //Serial.println(code.value, HEX);
    ControlRemoteDecoder(code.value);
    ir.resume();
    //delay(300);
  }
}
