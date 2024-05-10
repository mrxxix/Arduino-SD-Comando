#include <IRremote.h>                       // Biblioteca do recetor de infravermelhos

const int pinoLedVermelho = 11;
const int pinoLedVerde = 12;
const int pinoLedAzul = 13;
int pinoInfraVermelhos = 6;                 //define input pin on Arduino

IRrecv irrecv(pinoInfraVermelhos);
decode_results results;


void setup() {
  pinMode(pinoLedVermelho, OUTPUT); 
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedAzul, OUTPUT);  
  pinMode(pinoInfraVermelhos, INPUT); 
  irrecv.enableIRIn();                      // Start the receiver 
  Serial.begin(9600); 
}


void loop() {
  int i=0;

  if (irrecv.decode(&results)) {
  translateIR();
  irrecv.resume();                          // Recebe o próximo valor
  }  


}


 void translateIR()         // takes action based on IR code received describing Car MP3 IR codes 
{

  switch(results.value){
  case 0xFFA25D:  
    Serial.println(" CH-            "); 
    break;
  case 0xFF629D:  
    Serial.println(" CH             "); 
    break;
  case 0xFFE21D:  
    Serial.println(" CH+            "); 
    break;
  case 0xFF22DD:  
    Serial.println(" blue LED off          "); 
    digitalWrite(13,LOW);
    break;
  case 0xFF02FD:  
    Serial.println(" blue LED on        "); 
    digitalWrite(13, HIGH);
    break;
  case 0xFFC23D:  
    Serial.println(" PLAY/PAUSE     "); 
    break;
  case 0xFFE01F:  
    Serial.println(" VOL-           "); 
    break;
  case 0xFFA857:  
    Serial.println(" VOL+           "); 
    break;
  case 0xFF906F:  
    Serial.println(" EQ             "); 
    break;
  case 0xFF6897:  
    Serial.println(" 0              "); 
    break;
  case 0xFF9867:  
    Serial.println(" 100+           "); 
    break;
  case 0xFFB04F:  
    Serial.println(" 200+           "); 
    break;
  case 0xFF30CF:  
    Serial.println(" 1              ");
    digitalWrite(pinoLedVermelho, HIGH);
    delay(20);
    digitalWrite(pinoLedVermelho, LOW);
    break;

  case 0xFF18E7:  
    Serial.println(" 2              ");
    digitalWrite(pinoLedVerde, HIGH);
    delay(20);
    digitalWrite(pinoLedVerde, LOW);
    break;

  case 0xFF7A85:  
    Serial.println(" 3              ");
    digitalWrite(pinoLedAzul, HIGH);
    delay(20);
    digitalWrite(pinoLedAzul, LOW);
    break;

  case 0xFF10EF:  
    Serial.println(" 4              "); 
    break;

  case 0xFF38C7:  
    Serial.println(" 5              "); 
    break;

  case 0xFF5AA5:  
    Serial.println(" 6              "); 
    break;

  case 0xFF42BD:  
    Serial.println(" 7              "); 
    break;

  case 0xFF4AB5:  
    Serial.println(" 8              "); 
    break;

  case 0xFF52AD:  
    Serial.println(" 9              "); 
    break;

  default: 
    Serial.print(" unknown button   ");
    Serial.println(results.value, HEX);

  }

  delay(10);


} 
