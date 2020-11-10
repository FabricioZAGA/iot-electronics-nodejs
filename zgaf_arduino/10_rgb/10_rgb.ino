
const unsigned char RED= 9;

const unsigned char GREEN= 7;

const unsigned char BLUE= 8;

unsigned char contador =0;
const unsigned char RGB[]={RED,GREEN,BLUE};

void setup() {
  // put your setup code here, to run once:
  for(unsigned char i=0; i<sizeof(RGB); i++)

  pinMode(RGB[i],OUTPUT);
  

}

void leds(unsigned char valor){
  switch(valor){
    case 0:

    digitalWrite(RED,LOW);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,LOW);
    break;

     case 1:

    digitalWrite(RED,LOW);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,HIGH);
    break;

     case 2:

    digitalWrite(RED,LOW);
    digitalWrite(GREEN,HIGH);
    digitalWrite(BLUE,LOW);
    break;

     case 3:

    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,LOW);
    break;

     case 4:

    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,HIGH);
    break;

     case 5:

    digitalWrite(RED,LOW);
    digitalWrite(GREEN,HIGH);
    digitalWrite(BLUE,HIGH);
    break;

     case 6:

    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,HIGH);
    digitalWrite(BLUE,LOW);
    break;

     case 7:

    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,HIGH);
    digitalWrite(BLUE,HIGH);
    break;

    default:
    break;
    
    
    
    }
  
  }

void loop() {
  // put your main code here, to run repeatedly:
delay(1000);
if(contador==7)
contador =0;

else

contador++;

leds(contador);
}
