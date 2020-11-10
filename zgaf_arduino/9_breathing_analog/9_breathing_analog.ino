unsigned char cont = 0;
unsigned char valor = 0;


void setup() {
  // put your setup code here, to run once:
  
    pinMode (2, OUTPUT);
    pinMode (3, OUTPUT);
    pinMode (4, OUTPUT);
    pinMode (5, OUTPUT);
    pinMode (6, OUTPUT);
    pinMode (7, OUTPUT);
    pinMode (8, OUTPUT);
    pinMode (9, OUTPUT);
    
  
}


void breathing(unsigned int leds, unsigned int dutyCycle){

  for(unsigned char i = 0; i < 255; i++){
    if(i < dutyCycle){
      digitalWrite(leds, HIGH);
      
    } else {
      digitalWrite(leds, LOW);
    }
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(6);
  
    breathing(2, cont);
    if(valor == 0) {
      if(cont<255){
        cont++;
      } else {
        valor = 1;
      }
    } else {
      if(cont>0){
        cont--;
      } else {
        valor = 0;
      }
    }
      breathing(3, cont);
    if(valor == 0) {
      if(cont<255){
        cont++;
      } else {
        valor = 1;
      }
    } else {
      if(cont>0){
        cont--;
      } else {
        valor = 0;
      }
    }
      breathing(4, cont);
    if(valor == 0) {
      if(cont<255){
        cont++;
      } else {
        valor = 1;
      }
    } else {
      if(cont>0){
        cont--;
      } else {
        valor = 0;
      }
    }
      breathing(5, cont);
    if(valor == 0) {
      if(cont<255){
        cont++;
      } else {
        valor = 1;
      }
    } else {
      if(cont>0){
        cont--;
      } else {
        valor = 0;
      }
    }
      breathing(6, cont);
    if(valor == 0) {
      if(cont<255){
        cont++;
      } else {
        valor = 1;
      }
    } else {
      if(cont>0){
        cont--;
      } else {
        valor = 0;
      }
    }
  breathing(7, cont);
    if(valor == 0) {
      if(cont<255){
        cont++;
      } else {
        valor = 1;
      }
    } else {
      if(cont>0){
        cont--;
      } else {
        valor = 0;
      }
    }
      breathing(8, cont);
    if(valor == 0) {
      if(cont<255){
        cont++;
      } else {
        valor = 1;
      }
    } else {
      if(cont>0){
        cont--;
      } else {
        valor = 0;
      }
    }
      breathing(9, cont);
    if(valor == 0) {
      if(cont<255){
        cont++;
      } else {
        valor = 1;
      }
    } else {
      if(cont>0){
        cont--;
      } else {
        valor = 0;
      }
    }
  
    

}
