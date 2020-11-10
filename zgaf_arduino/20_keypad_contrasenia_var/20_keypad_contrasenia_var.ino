unsigned char filas[] = {2, 3, 4, 5}; //L1, L2, L3, L4
  unsigned char columnas[] = {6, 7, 8, 9};
unsigned char tecla = 1;
bool b_serial = false;
bool b_presionado = false; unsigned char teclaTemporal = 0;
unsigned int pwmVal = 0;
void salidas(unsigned char valor){ unsigned char cociente = valor; unsigned char residuo = 0;
//C1, C2, C3, C4
for (unsigned int i = sizeof(filas); i > 0; i--) { residuo = cociente % 2;
cociente = (cociente - residuo) / 2; if(residuo == 1) {
digitalWrite(filas[i-1], HIGH); } else {
digitalWrite(filas[i-1], LOW); }
} }
unsigned char entradas(){ unsigned char valor = 0;
if (digitalRead(columnas[3])) {
valor += 1; }
if (digitalRead(columnas[2])) { valor += 2;
}
if (digitalRead(columnas[1])) {
valor += 4; }
if (digitalRead(columnas[0])) { valor += 8;
}
return valor; }
unsigned char teclado (void) {
unsigned char car;
salidas(0b1110); //15 , 0x0F , 0b1111 car = entradas();

switch(car) { case 0b1110:
return 'D'; break;
case 0b1101: return '#';
break;
case 0b1011:
return '0'; break;
case 0b0111: return '*';
break; }
salidas(0b1101); car = entradas(); switch(car) {
case 0b1110: return 'C';
break;
case 0b1101:
return '9'; break;
case 0b1011: return '8';
break;
case 0b0111:
return '7'; break;
}

salidas(0b1011); car = entradas(); switch(car) {
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
return '1';

break; }
return 1; }
void setup() {
Serial.begin(9600);
for (unsigned int i = 0; i < sizeof(columnas); i++) {
pinMode(columnas[i], INPUT_PULLUP); }
for (unsigned int i = 0; i < sizeof(filas); i++) { pinMode(filas[i], OUTPUT);
}
Serial.println("TECLADO CONTRASENIA VARIABLE"); }
void loop() {
tecla = teclado(); if(tecla != 1) {
b_presionado = true;
teclaTemporal = tecla; } else {
if(b_presionado) { b_presionado = false; b_serial = true;
tecla = teclaTemporal;

} }
if(b_serial){
b_serial = false;
if (tecla >= '0' && tecla <= '9') {
Serial.write(tecla); pwmVal *= 10; pwmVal += (tecla -48);
} else {
switch (tecla) {
case 'A':
Serial.write(10);
if (pwmVal <= 100 && pwmVal != 0) {
Serial.println("SE HA ESTABLECIDO CORRECTAMENTE");
analogWrite(10, 2.55 * pwmVal); // 255 if 255 is 100%, 1% is 2.55 so we will make a multiplication of 2.55 x value, until we reach 255
} else if (pwmVal == 0) {
Serial.println("CORRECTO");
analogWrite(10, pwmVal); // 255 if 255 is 100%, 1% is 2.55 so we will make a multiplication of 2.55 x value, until we reach 255
} else {
Serial.println("Incorrect... the value must be under 100%");
}
pwmVal = 0;
Serial.println("INSERTA UN NUEVO VALOR"); break;
case 'C':
Serial.println("CORRECTO");

analogWrite(10, pwmVal); // 255 if 255 is 100%, 1% is 2.55 so we will make a multiplication of 2.55 x value, until we reach 255
break; default:
Serial.println("Incorrect command: "); break;
} }
} }
