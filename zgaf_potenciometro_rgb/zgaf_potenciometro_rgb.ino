unsigned int signals[3] = {0,0,0};
unsigned char potR = A0;
unsigned char potG = A1;
unsigned char potB = A2;

unsigned char pots[3] = {potR,potG,potB};

unsigned char R = 0;
unsigned char G = 0;
unsigned char B = 0;

double real = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  signals[0] = analogRead(pots[0]);
  signals[1] = analogRead(pots[1]);
  signals[2] = analogRead(pots[2]);


  R = map(signals[0], 0, 1023, 0, 255);
  G = map(signals[1], 0, 1023, 0, 255);
  B = map(signals[2], 0, 1023, 0, 255);

  Serial.println(R); 
}
