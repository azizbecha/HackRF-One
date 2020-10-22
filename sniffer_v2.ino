#include <SoftwareSerial.h>
#include <IRremote.h>
int BUTTON1 = 3;
int receiver = 8;
/* int emitter = 9; */
IRrecv irrecv(receiver); 
decode_results results;
/*IRsend irsend(emitter);*/

void setup() {
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  Serial.begin(9600);

 irrecv.enableIRIn();
  
 ////////////////////////////////////////////
 digitalWrite(13,OUTPUT);
 Serial.println("root@HackRF: ");
 delay(150);
  Serial.println("Project Made By Aziz Becha");
   delay(150);
  Serial.println("Github: github.com/AzizVirus");
   delay(150);
  Serial.println("---  Sniffing Mode Was Started ---");
  delay(150);
  Serial.println("The Captured Handshakes Will Be Displayed Here");
   delay(150);
  Serial.println("-----  Happy Hacking  -----");
  //////////////////////////////////////////////////////////////////
  
}

void loop() {
  
/////////////////////////////////////
if (digitalRead(BUTTON1) == HIGH) {
  digitalWrite(13,HIGH);
  Serial.println("Button 1 pressed");
  delay(300);
//  irsend.sendNEC(0x99D8477D, 32);//
}
else {
  digitalWrite(13,LOW);
  }
/////////////////////////////

 if (irrecv.decode(&results)) {
  digitalWrite(13,HIGH);
  delay(200);
  Serial.print("Captured handshake: ");
 Serial.println (results.value, HEX);  
 irrecv.resume(); 
 
 }

 }
