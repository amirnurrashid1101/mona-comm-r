 #define cr_pin 11

int LED1 = 13; //Mona Top LED

// pin config for basic platform test
// Motors
int Motor_right_PWM = 10;  //   0 (min speed) - 255 (max speed) 
int Motor_right_direction = 5;  //   0 Forward - 1 Reverse
int Motor_left_PWM = 9;    //   0 (min speed) - 255 (max speed)  
int Motor_left_direction = 6;   //   0 Forward - 1 Reverse
#define Forward 1//0
#define Reverse 0//1

void reverse(int delay_time){
  analogWrite(Motor_right_PWM,40); // right motor
  digitalWrite(Motor_right_direction,Reverse); //right
  analogWrite(Motor_left_PWM, 40); // left 
  digitalWrite(Motor_left_direction,Reverse); //left
  delay(delay_time);
}

//PACKET DEFAULT
String header = "11";
String ID = "01";

//Received Parameters
String incomingPacket = " ";
String rx_header = " ";
String rx_ID = " ";
String rx_information = " ";

void setup() {
  pinMode(LED1, OUTPUT);
  
  Serial.begin(2400);
  while (!Serial);
  Serial.println("Slave RX");
  //Serial.println("DISTANCE TESTING, 40cm");

  tone(cr_pin, 38000);  /* For modulation at 38kHz */
}

  
void loop() {
  //digitalWrite(LED1,HIGH); //Top LED
  //ON_LED();
  incomingPacket = rx(incomingPacket);
  //Serial.println(incomingPacket);
  
  //Decode packet
  rx_header = incomingPacket.substring(0,2);
  Serial.print("rx_header: ");
  Serial.println(rx_header);
  //if header match, decode rest of packet
  if(rx_header == header){
    rx_ID = incomingPacket.substring(2,4);
    rx_information =  incomingPacket.substring(4,8);
    if(rx_ID == ID){
      Serial.print("rx_information: ");
      Serial.println(rx_information);
    }
  }
  
  /*
  //Display incomingPacket -For Testing Distance,Angle,
  if (incomingPacket !=" "){
    Serial.print("PACKET: ");
    Serial.println(incomingPacket);
    Serial.println("HEADER: " + rx_header);
    Serial.println("ID: " + rx_ID);
    Serial.println("Instruction: " + rx_information);
  
    //if header match save data, else dont store
    }
  */
  /*
  //Read information, Do something.
  if (rx_information == "1001"){
    Serial.println("Moving to location");
    //digitalWrite(LED1,LOW); //Top LED
    //OFF_LED();
    }
  else if (rx_information == "1010"){
    Serial.println("Rerouting");
    //OFF_LED();
    //digitalWrite(LED1,LOW); //Top LED
    }
   */
  
  incomingPacket = " ";
  Serial.flush();
  delay(1000);
}

void ON_LED(){
  digitalWrite(LED1,HIGH); //Top LED
  }

void OFF_LED(){
  digitalWrite(LED1,LOW); //Top LED
  }

//Reciever
String rx(String inPacket){
  /* If data is available on serial port */
  if(Serial.available()){ 

    inPacket = Serial.readString();
     
    delay(1000);
  }//end if serial available
  
  return inPacket;
 } //end tx
