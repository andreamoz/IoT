#include <Bridge.h>
#include <BridgeClient.h>

int pinSensore = A0;

int pinRosso = 11;
int pinVerde = 9;
int pinBlu = 10;

String dati = "";

BridgeClient client;

void setup() {
  pinMode(pinRosso, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBlu, OUTPUT);
  
  // introduciamo un ritardo per assicurarci che tutto sia pronto
  // prima di provare a far partire la rete
  delay(2000);
  // inizializza la rete
  Bridge.begin();
  Serial.begin(9600);
}

void loop() {
  int lettura = analogRead(pinSensore);
  float tensione = lettura * 5000.0 / 1024;
  float temperatura = (tensione - 500) / 10;

  dati = "temperatura=";
  dati += String(temperatura);

  aggiornaDatiRemoti(dati);

  delay(1000);
}

void aggiornaDatiRemoti(String dati){
  Serial.println(dati);
  if (client.connect("192.168.1.5", 80)) {
    digitalWrite(pinRosso, LOW);
    digitalWrite(pinVerde, HIGH);
    Serial.println("Collegamento riuscito");
    client.println("POST /IoT/aggiornaDati.php HTTP/1.1");
    client.println("Host: 192.168.1.5");
    client.println("User-Agent: Arduino/1.0");
    client.println("Connection: close");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(dati.length());
    client.println();
    client.println(dati);
    delay(1000);
  } else {
    Serial.println("Collegamento NON riuscito");
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinRosso, HIGH);
  }
  
  if (client.connected()) {
    client.stop();
  }
  
}

