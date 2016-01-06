String[] temperatura = new String[1];

void setup(){
  temperatura[0] = String.valueOf(21);
}

void draw(){
  saveStrings("C:/wamp/www/IoT/temperatura.txt", temperatura);
  
  delay(1000);
}