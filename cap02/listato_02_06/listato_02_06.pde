import processing.serial.*;

Serial portaSeriale;
String[] temperatura = new String[1];

void setup(){
  // stampa sulla console l'elenco delle porte seriali disponibili
  printArray(Serial.list()); 
  
  // prende il nome per la porta seriale dal primo elemento della lista
  // attenzione: a volte potrebbe essere necessario modificare l'indice
  String nomePortaSeriale = Serial.list()[0];
  
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
  println(datoLetto);
  
  // imposta il valore della temperatura
  datoLetto = trim(datoLetto);
  temperatura[0] = datoLetto;
  // salva la temperatura sul file che verrà letto dalla pagina web
  saveStrings("C:/wamp64/www/IoT/temperatura.txt", temperatura);
}