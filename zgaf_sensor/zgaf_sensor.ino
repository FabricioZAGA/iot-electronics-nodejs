/*
 * created by Rui Santos, https://randomnerdtutorials.com
 * 
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
 
int trigPin = 53;    // Trigger
int echoPin = 52;    // Echo
long duration, cm, cm_temp, inches;
long acumulado = 0;
unsigned char muestra = 0;
unsigned char muestras = 100;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  if(muestra < muestras) {
      acumulado += (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
      muestra++;
  }
  else {
    cm_temp = acumulado / muestra;
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
