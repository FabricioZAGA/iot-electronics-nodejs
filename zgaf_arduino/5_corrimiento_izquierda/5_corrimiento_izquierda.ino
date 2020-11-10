
unsigned char pines[]={11,10,9,6,5,4,3,2};
unsigned char contador=0;



void setup() {
  // put your setup code here, to run once:

  for(char i=0;i<sizeof(pines); i++ ){
    pinMode(pines[i],OUTPUT);
    
    }

}

void loop() {
  // put your main code here, to run repeatedly:

  
delay(100);

if(contador==8)
contador=0;

else
contador++;

for(char i=0; i < sizeof(pines); i++)
{

  if(contador==i) 
  {
    digitalWrite(pines[i],HIGH);
    
    }

    else
    digitalWrite(pines[i],LOW);
    
  
  }
}
