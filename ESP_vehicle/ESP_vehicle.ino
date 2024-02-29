//Robokabaddi on-vehicle ESP 
#define in1 32 //Motor1  L293 Pin in1 
#define in2 33 //Motor1  L293 Pin in2
#define in3 25 //Motor2  L293 Pin in3 
#define in4 26 //Motor2  L293 Pin in4 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //for bo dc motors
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

      if (command == 'F'){
      Forward(); // move forward
    }else if (command == 'L'){
      Left();  // move left
    }else if (command == 'R'){
      Right();  // move right
    }else{
      Stop();     // stop
    }
    
}

void Forward(){  //forword

analogWrite(in1, 80); //Right Motor forword Pin 
analogWrite(in2, 0);  //Right Motor backword Pin 

analogWrite(in3, 80);  //Left Motor backword Pin 
analogWrite(in4, 0); //Left Motor forword Pin 

}
void Right(){ //turnRight

analogWrite(in1, 170);  //Right Motor forward Pin 

analogWrite(in2, 0); //Right Motor backward Pin  

analogWrite(in3, 0);  //Left Motor backward Pin 

analogWrite(in4, 170); //Left Motor forward Pin 

}

void Left(){ //turnLeft

analogWrite(in1, 0); //Right Motor forword Pin 
analogWrite(in2, 170);  //Right Motor backword Pin 

analogWrite(in3, 170); //Left Motor backword Pin 
analogWrite(in4, 0);  //Left Motor forword Pin 

}

void Stop(){ //stop

analogWrite(in1, 0); //Right Motor forword Pin 
analogWrite(in2, 0); //Right Motor backword Pin 
analogWrite(in3, 0); //Left Motor backword Pin 
analogWrite(in4, 0); //Left Motor forword Pin 

}


// #include <esp_now.h>
// #include <WiFi.h>

// // Replace with the MAC address of the sending ESP32
// uint8_t senderMacAddress[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

// void setup() {
//   Serial.begin(115200);

//   // Set device as a Wi-Fi Station
//   WiFi.mode(WIFI_STA);

//   // Initialize ESP-NOW
//   if (esp_now_init() != ESP_OK) {
//     Serial.println("Error initializing ESP-NOW");
//     return;
//   }

//   // Register peer
//   esp_now_peer_info_t peerInfo;
//   memcpy(peerInfo.peer_addr, senderMacAddress, 6);
//   peerInfo.channel = 0;
//   peerInfo.encrypt = false;

//   if (esp_now_add_peer(&peerInfo) != ESP_OK) {
//     Serial.println("Failed to add peer");
//     return;
//   }
// }

// void loop() {
//   uint8_t receivedData[32]; // Adjust the buffer size based on your data size
//   int dataLength = sizeof(receivedData);

//   // Receive data
//   esp_err_t result = esp_now_recv(NULL, receivedData, &dataLength, 0);

//   if (result == ESP_OK) {
//     // Print received data
//     String receivedString = String((char*)receivedData);
//     Serial.println("Received data: " + receivedString);
//   } else if (result == ESP_ERR_ESPNOW_NOT_FOUND) {
//     // No data received
//   } else {
//     Serial.println("Error receiving data");
//   }

//   delay(100); // Adjust the delay based on your requirements
// }
