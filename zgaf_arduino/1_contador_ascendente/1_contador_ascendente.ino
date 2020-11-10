unsigned char leds[]={2,3,4,5,6,9,10,11};
unsigned char contador=0;



void setup() {
  // put your setup code here, to run once:
  for (unsigned char i=0;i<sizeof(leds); i++)
  pinMode(leds[i],OUTPUT);
  

}

void decToBin(unsigned char decimal){
  unsigned char residuo=0;
  unsigned char cociente=decimal;

  for(unsigned char i=0;i<sizeof(leds); i++){
    
    
     residuo = cociente % 2;
     cociente = cociente / 2;

      if(residuo ==1)

    digitalWrite(leds[i],HIGH);
    else
    
     digitalWrite(leds[i],LOW);
    
    }
  
  }

void loop() {
  delay(100);
if(contador==255)
contador=0;

else
contador++;

decToBin(contador);

}
