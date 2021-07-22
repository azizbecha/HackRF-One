/*
-------------  README  --------------
-------------------------------------

Project: HackRF One Remake By Arduino Nano 
Author: Aziz Becha
Concept: Hack Cars Easily by capturing the remote's radio signals
Github profile: https://github.com/AzizVirus
GitHub Repository: https://github.com/AzizVirus/HackRF-One
Follow My Github to Receive The Updates

------------------------------------
------------------------------------
*/

// Include the IRremote Library (https://github.com/Arduino-IRremote/Arduino-IRremote)
#include <IRremote.h>

// Define buttons
int BUTTON1 = 3;
int BUTTON2 = 4;
int BUTTON3 = 5;
int BUTTON4 = 6;

// Define LEDs
int LED_INDICATOR = 13;
 
// Define emitters & recivers
int receiver = 8;
// int emitter = 9; 


/*IRsend irsend(emitter);*/
IRrecv irrecv(receiver); 
decode_results results;

void setup() {
  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2,INPUT);
  pinMode(BUTTON3,INPUT);
  pinMode(BUTTON4,INPUT);
  digitalWrite(LED_INDICATOR,OUTPUT);
  Serial.begin(115200);
  irrecv.enableIRIn();
  blinking();
  banner();
}

void loop() {

//  ----------------------  //
if (digitalRead(BUTTON1) == HIGH) {
  digitalWrite(LED_INDICATOR,HIGH);
  Serial.println("New Action Detected !"); 
  Serial.println("Button 1 pressed");
  Serial.println("-------------------------------------");
  delay(300);
// irsend.sendNEC(0x99D8477D, 32);// 
}
else {
  digitalWrite(LED_INDICATOR,LOW);
  }
  
if (irrecv.decode(&results)) {
 digitalWrite(LED_INDICATOR,HIGH);
 delay(200);
 Serial.println("New Action Detected !"); 
 Serial.print("Captured handshake (HEX Form): ");
 Serial.println (results.value, HEX);
 Serial.print("Binary Form: " );
 Serial.println (results.value, BIN);  
 Serial.print("-------------------------------------");
 Serial.println("");
 irrecv.resume(); }

 }

 void blinking() {
  digitalWrite(LED_INDICATOR, HIGH);
  delay(120);
  digitalWrite(LED_INDICATOR, LOW);
  delay(120);
  digitalWrite(LED_INDICATOR, HIGH);
  delay(120);
  digitalWrite(LED_INDICATOR, LOW);
  delay(120);
  digitalWrite(LED_INDICATOR, HIGH);
  delay(120);
  digitalWrite(LED_INDICATOR, LOW);
  delay(120);
  digitalWrite(LED_INDICATOR, HIGH);
  delay(120);
  digitalWrite(LED_INDICATOR, LOW);
  delay(120);
  digitalWrite(LED_INDICATOR,HIGH);
  delay(120);  
  digitalWrite(LED_INDICATOR, LOW);
  delay(120);
  digitalWrite(LED_INDICATOR,HIGH);
  delay(120);
  digitalWrite(LED_INDICATOR, LOW);
  delay(120);
  digitalWrite(LED_INDICATOR,HIGH);
  delay(120); }
  /*------------------------------------*/
  void banner() {   
     Serial.println("root@HackRF: info");
 delay(300);
  Serial.println("Project Made By Aziz Becha");
   delay(300);
  Serial.println("Github: github.com/AzizVirus");
   delay(300);
  Serial.println("---  Sniffing Mode Was Started ---");
  delay(300);
  Serial.println("The Captured Handshakes Will Be Displayed Here");
   delay(300);
  Serial.println("-----  Happy Hacking  -----");
  Serial.println("-------------------------------------");
    }

/* Project Coded BY Aziz BeCha (Author) And IR remote Library */
/* Github: https://github.com/AzizVirus */
