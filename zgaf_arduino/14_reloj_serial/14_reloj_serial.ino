unsigned int horas = 0;
unsigned int minutos = 0;
unsigned int segundos = 0;
unsigned char tiempo;

void setup() {
  // put your setup code here, to run once:
   
  Serial.begin(9600);
  Serial.write(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(segundos == 60){
    segundos = 0;
    minutos++;
  }
  if(minutos == 60){
    minutos = 0;
    horas++;
  }
  if(horas == 24){
    horas = 0;
  }
  
  if(horas < 10) {
     
    Serial.print("0");
  }
  Serial.print(horas);
  Serial.print(":");
  if(minutos < 10) {
    Serial.print("0");
  }
  Serial.print(minutos);
  Serial.print(":");
  if(segundos < 10) {
    Serial.print("0");
  }
  Serial.print(segundos);
  Serial.write(10);
  segundos++;
  delay(1000);
}
