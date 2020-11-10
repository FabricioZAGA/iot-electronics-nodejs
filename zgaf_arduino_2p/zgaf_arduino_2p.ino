#include <IRremote.h> 
String statusLight = "off";
unsigned char infrarrojo = 13; 
unsigned int password = 1234; 
unsigned int pwd = 0; 
unsigned int temporal;
IRrecv ir(infrarrojo);
decode_results code;
unsigned char filas[] = {2, 3, 4, 5};
unsigned char columnas[] = {6, 7, 8, 9}; //C1, C2, C3, C4
unsigned char tecla = 1;
bool b_serial = false;
  //L1, L2, L3, L4
bool b_presionado = false; 
unsigned char teclaTemporal = 0;

void salidas(unsigned char valor)
{
unsigned char cociente = valor;
unsigned char residuo = 0;
for (unsigned int i = sizeof(filas); i > 0; i--)
{ 
 residuo = cociente % 2;
cociente = (cociente - residuo) / 2; 
if(residuo == 1)
digitalWrite(filas[i-1], HIGH); 
else
digitalWrite(filas[i-1], LOW); 
}
}
unsigned char entradas()
{
unsigned char valor = 0;
if (digitalRead(columnas[3])) {
valor += 1; }
if (digitalRead(columnas[2])) { valor += 2;
}
if (digitalRead(columnas[1])) {
valor += 4; }
if (digitalRead(columnas[0])) {

valor += 8; }
return valor; }
unsigned char teclado (void) {
unsigned char car; 
salidas(0b1110); 
car = entradas(); 
switch(car) 
{
case 0b1110: return 'D';
break;
case 0b1101:
return '#'; break;
case 0b1011: return '0';
break;
case 0b0111:
return '*'; break;
} salidas(0b1101); car = entradas(); switch(car) {
case 0b1110: return 'C';
//15 , 0x0F , 0b1111

break;
case 0b1101:
return '9'; break;
case 0b1011: return '8';
break;
case 0b0111:
return '7'; break;
} salidas(0b1011); car = entradas(); switch(car) {
case 0b1110: return 'B';
break;
case 0b1101:
return '6'; break;
case 0b1011: return '5';
break;
case 0b0111:
return '4'; break;
} salidas(0b0111); car = entradas(); switch(car) {

case 0b1110: return 'A';
break;
case 0b1101:
return '3'; break;
case 0b1011: return '2';
break;
case 0b0111:
return '1'; break;
}
return 1; }

void ControlRemoteDecoder(unsigned int codigo) {
switch(codigo) { case 0xFF906F:
pwd = 0; Serial.print("ok"); Serial.write(10);
break;
case 0xFF6897: temporal = pwd; if(temporal < 9999){
temporal *= 10; temporal += 0; if(temporal < 9999) {

pwd = temporal; Serial.print(pwd); Serial.write(10);
} }
break;
case 0xFF30CF: temporal = pwd; if(temporal < 9999){
temporal *= 10; temporal += 1; if(temporal < 9999) {
pwd = temporal; Serial.print(pwd); Serial.write(10);
} }
break;
case 0xFF18E7: temporal = pwd; if(temporal < 9999){
temporal *= 10; temporal += 2; if(temporal < 9999) {
pwd = temporal; Serial.print(pwd); Serial.write(10);
} }
break;

case 0xFF7A85: temporal = pwd; if(temporal < 9999){
temporal *= 10; temporal += 3; if(temporal < 9999) {
pwd = temporal; Serial.print(pwd); Serial.write(10);
} }
break;
case 0xFF10EF: temporal = pwd; if(temporal < 9999){
temporal *= 10; temporal += 4; if(temporal < 9999) {
pwd = temporal; Serial.print(pwd); Serial.write(10);
} }
break;
case 0xFF38C7: temporal = pwd; if(temporal < 9999){
temporal *= 10; temporal += 5; if(temporal < 9999) {

pwd = temporal; Serial.print(pwd); Serial.write(10);
} }
break;
case 0xFF5AA5: temporal = pwd; if(temporal < 9999){
temporal *= 10; temporal += 6; if(temporal < 9999) {
pwd = temporal; Serial.print(pwd); Serial.write(10);
} }
break;
case 0xFF42BD: temporal = pwd; if(temporal < 9999){
temporal *= 10; temporal += 7; if(temporal < 9999) {
pwd = temporal; Serial.print(pwd); Serial.write(10);
} }
break;

case 0xFF4AB5: temporal = pwd; if(temporal < 9999){
temporal *= 10; temporal += 8; if(temporal < 9999) {
pwd = temporal; Serial.print(pwd); Serial.write(10);
} }
break;
case 0xFF52AD: temporal = pwd; if(temporal < 9999){
temporal *= 10; temporal += 9; if(temporal < 9999) {
pwd = temporal; Serial.print(pwd); Serial.write(10);
} }
break; }
}

void setup() {
Serial.begin(9600);
pinMode(10, OUTPUT);
// Control setup
ir.enableIRIn();
for (unsigned char i = 0; i<sizeof(columnas); i++) { pinMode(columnas[i], INPUT_PULLUP);
}
for (unsigned char i = 0; i<sizeof(filas); i++) { pinMode(filas[i], OUTPUT);
} }
void loop() {
// put your main code here, to run repeatedly:
if (ir.decode(&code)) { ControlRemoteDecoder(code.value); ir.resume();
}
tecla = teclado(); if (tecla != 1) {
b_presionado = true;
teclaTemporal = tecla; } else {
if (b_presionado) { b_presionado = false; b_serial = true;

tecla = teclaTemporal; }
}
if(b_serial){
b_serial = false;
if (tecla >= '0' && tecla <= '9') {
if(pwd < 9999) { pwd *= 10;
pwd += (tecla -48);
} Serial.print(pwd); Serial.write(10);
} else {
switch (tecla) {
case 'A':
pwd = 0; Serial.print("ok"); Serial.write(10);
break; }
} }
if (Serial.available() > 0) {
statusLight = Serial.readStringUntil('\n'); 
delay(300);
if (statusLight == "on") {
digitalWrite(10, HIGH); pwd = 0;


} 
else 
{
digitalWrite(10, LOW); pwd = 0;
} }
}
