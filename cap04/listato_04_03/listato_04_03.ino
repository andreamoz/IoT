#include <Ethernet.h>
#include <SPI.h>

// indirizzo MAC dello shield Ethernet
byte mac[] = {0x90, 0xA2, 0xDA, 0x09, 0x00, 0x93};
// indirizzo IP che vogliamo assegnare al dispositivo
byte ip[] = {192, 168, 1, 21};
// indirizzo IP del server dns (di solito il router)
byte ip_dns[] = {192, 168, 1, 1};
// indirizzo IP del gateway (di solito il router)
byte ip_gateway[] = {192, 168, 1, 1};
// maschera di rete
byte subnet[] = {255, 255, 255, 0};

int pinSensore = A0;

String dati = "";

EthernetClient client;

void setup() {
  // introduciamo un ritardo per assicurarci che tutto sia pronto
  // prima di provare a far partire la rete
  delay(2000);
  // inizializza la rete
  Ethernet.begin(mac, ip, ip_dns, ip_gateway, subnet);
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
  if (client.connect("192.168.1.5/IoT", 80)) {
    Serial.println("Collegamento riuscito");
  } else {
    Serial.println("Collegamento NON riuscito");
  }

  if (client.connected()) {
    client.stop();
  }
}
