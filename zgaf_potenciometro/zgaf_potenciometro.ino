double senial = 0;
unsigned char potenciometro = A7;

double real = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  senial = analogRead(potenciometro);
  real = (senial * 5) / 1023;

  Serial.print("Valor de ADC es: ");
  Serial.println(senial);
  Serial.print("Valor real:");
  Serial.println(real);
}
