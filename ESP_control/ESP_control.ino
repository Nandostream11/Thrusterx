
#define Left_VRX_PIN 25
#define Left_VRY_PIN 26

int x_val;
int y_val;


// #define F 35  
// #define L 32
// #define R 33

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(Left_VRX_PIN, INPUT);
  pinMode(Left_VRY_PIN, INPUT);
  // pinMode(F, INPUT); 
  // pinMode(L, INPUT);
  // pinMode(R, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  x_val = map(analogRead(Left_VRX_PIN),0,4095,-100,255);//value 0-255 (">> 4" convert maximum value from 4095 to 255 )
  y_val = map(analogRead(Left_VRY_PIN),0,4095,-100,255);//value 0-255  
  
  Serial.printf("x: %d, y: %d\n", x_val, y_val);

  delay(100);
  // message();
}

// void message(){
//   if()
//   else

// }

// #include <esp_now.h>
// #include <WiFi.h>

// // Replace with the MAC address of the receiving ESP32
// uint8_t receiverMacAddress[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

// const int xAxisPin = 34; // Analog pin for X-axis
// const int yAxisPin = 35; // Analog pin for Y-axis

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
//   memcpy(peerInfo.peer_addr, receiverMacAddress, 6);
//   peerInfo.channel = 0;
//   peerInfo.encrypt = false;

//   if (esp_now_add_peer(&peerInfo) != ESP_OK) {
//     Serial.println("Failed to add peer");
//     return;
//   }
// }

// void loop() {
//   int xValue = analogRead(xAxisPin); // Read X-axis value
//   int yValue = analogRead(yAxisPin); // Read Y-axis value

//   // Map the analog values (0-4095) to a range (0-255) for better readability
//   int xMapped = map(xValue, 0, 4095, 0, 255);
//   int yMapped = map(yValue, 0, 4095, 0, 255);

//   // Prepare data to send
//   String dataToSend = String(xMapped) + "," + String(yMapped);
//   uint8_t data[dataToSend.length() + 1];
//   dataToSend.getBytes(data, dataToSend.length() + 1);

//   // Send data
//   esp_err_t result = esp_now_send(receiverMacAddress, data, dataToSend.length() + 1);

//   if (result == ESP_OK) {
//     Serial.println("Data sent successfully");
//   } else {
//     Serial.println("Error sending data");
//   }

//   delay(100); // Adjust the delay based on your requirements
// }
