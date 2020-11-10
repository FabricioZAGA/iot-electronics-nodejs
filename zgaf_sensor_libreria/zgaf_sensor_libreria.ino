#include <NewPing.h>
 
#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define MAX_DISTANCE 200

long acumulado = 0;
unsigned char muestra = 0;
unsigned char muestras = 100;
long cm = 0;
long cm_temp = 0;

// NewPing setup of pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);

}
 
void loop() {
  if(muestra < muestras) {
      acumulado += sonar.ping_cm();     // Divide by 29.1 or multiply by 0.0343
      muestra++;
  }
  else {
    cm_temp = acumulado / muestras;
    acumulado = 0;
    muestra = 0;
  }

  
  if(cm_temp != cm) {
    cm = cm_temp;
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    cm = cm_temp;
  }
}
