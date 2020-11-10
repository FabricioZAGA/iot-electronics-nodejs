
int leds;
void setup() {
  // put your setup code here, to run once:

  for(leds=2;leds<9;leds++){
    pinMode (leds, OUTPUT);
    
    }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(leds=2; leds<9; leds=leds+1){
    
    digitalWrite (leds, 1);
    delay (100);
 digitalWrite (leds, 0);
    delay (100);
    
    
    }

     for(leds=9; leds<2; leds=leds-1){
    
    digitalWrite (leds, 1);
    delay (100);
 digitalWrite (leds, 0);
    delay (100);
    
    
    }

     for(leds=9; leds>2; leds=leds-1){
    
    digitalWrite (leds, 1);
    delay (300);

    
    }

}
