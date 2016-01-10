import http.requests.*;
import processing.serial.*;

Serial portaSeriale;

void setup(){
  // stampa sulla console l'elenco delle porte seriali disponibili
  printArray(Serial.list()); 
  
  // prende il nome per la porta seriale dal primo elemento della lista
  // attenzione: a volte potrebbe essere necessario modificare l'indice
  String nomePortaSeriale = Serial.list()[2];
  
  // crea una nuova porta seriale e rimane in ascolto
  portaSeriale = new Serial(this, nomePortaSeriale, 9600);
  portaSeriale.bufferUntil('\n');
}

void draw(){
}

void serialEvent(Serial porta){
  // legge i dati in arrivo dalla porta seriale
  String datoLetto = porta.readStringUntil('\n');
  // stampa il valore letto sulla console
  // il comando può essere commentato
  // appena verificato il corretto funzionamento dello sketch
  // println(datoLetto);
  
  // ripulisce il valore letto
  datoLetto = trim(datoLetto);
  // richiede l'aggiornamento della temperatura sul server remoto
  aggiornaDatiRemoti("temperatura", datoLetto);
}

void aggiornaDatiRemoti(String parametro, String valore) {
  // istanzia un nuovo oggetto per la richiesta
  PostRequest post = new PostRequest("http://localhost/iot/aggiornaDati.php");
  // imposta i dati da inviare con la richiesta POST
  post.addData(parametro, valore);
  // invia la richiesta POST al server remoto
  post.send();
  // stampa la risposta del server remoto
  // il comando può essere commentato
  // appena verificato il corretto funzionamento dello sketch 
  println(post.getContent());
}