#define cr_pin 11

int LED1 = 13; //Mona Top LED

//PACKET
//FG Header 11, CD Header 10
String header = "11";
String ID = "01";
String information1 = "1001";
String information2 = "1010";
String information3 = "1011";
String information4 = "1100";
String information5 = "1101";
String packet1 = header+ID+information1;
String packet2 = header+ID+information2;
String packet3 = header+ID+information3;
String packet4 = header+ID+information4;
String packet5 = header+ID+information5;

int counter = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  
  Serial.begin(2400);
  while (!Serial);
  Serial.println("Master TX");

  tone(cr_pin, 38000);  /* For modulation at 38kHz */
}

void loop() {
  //digitalWrite(LED1,HIGH); //Top LED
  tx(packet1);
  delay(3000);
  
  tx(packet2);
  delay(3000);
  
  tx(packet3);
  delay(3000);
  
  tx(packet4);
  delay(3000);
  
  tx(packet5);
  delay(3000);

  Serial.flush();
  //digitalWrite(LED1,LOW); //Top LED

}

//Transmitter
 String tx(String txpacket){

   //Begin Transmission
   Serial.println(txpacket);
   delay(1000);
   

    return;
 }
