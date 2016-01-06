int pinSensore = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lettura = analogRead(pinSensore);
  float tensione = lettura * 5000 / 1024;
  float temperatura = (tensione - 500) / 10;

  Serial.println(temperatura);

  delay(1000);
}

