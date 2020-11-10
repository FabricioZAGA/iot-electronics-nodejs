unsigned char contador = 0;

void setup() {

  

}

void loop() {
  // put your main code here, to run repeatedly:
if(contador==255)
contador=0;

else
contador++;

delay(10);
  analogWrite(2,contador);
  analogWrite(3,contador);
  analogWrite(4,contador);
  analogWrite(5,contador);
  analogWrite(6,contador);
  analogWrite(7,contador);
  analogWrite(8,contador);
  analogWrite(9,contador);


}
