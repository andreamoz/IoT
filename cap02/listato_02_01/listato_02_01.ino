int pinSensore = A0;

void setup() {
}

void loop() {
  int lettura = analogRead(pinSensore);
  float tensione = lettura * 5000.0 / 1024;
  float temperatura = (tensione - 500) / 10;

  delay(1000);
}
