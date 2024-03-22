//D8:BC:38:FC:76:08
/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp32-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/
#include <esp_now.h>
#include <WiFi.h>

#define in1 32 //Motor1 PWM
#define in2 33 //Motor1 DIR
#define in3 26 //Motor2  L293 Pin in3 
#define in4 25 //Motor2  L293 Pin in4 

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    float a;
    float b;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  // Serial.print("Bytes received: ");
  // Serial.println(len);
  // Serial.print("BX: ");
  // Serial.println(myData.a);
  // Serial.print("LY: ");
  // Serial.println(myData.b);

}

void Forward(int a){  //forword
analogWrite(in1, a); //Right Motor forword Pin 
analogWrite(in2, 0);  //Right Motor backword Pin 
Serial.printf("%d, F\n",a);
analogWrite(in3, a); //Left Motor backword Pin 
analogWrite(in4, 255);  //Left Motor forword Pin 
} 

void Right(int a){ //turnRight
analogWrite(in1, a); //Right Motor forword Pin 
analogWrite(in2, 0);  //Right Motor backword Pin 
Serial.printf("%d, R\n",a);
analogWrite(in3, a);  //Left Motor backword Pin 
analogWrite(in4, 0); //Left Motor forword Pin 
}

void Left(int a){ //turnLeft
analogWrite(in1, a); //Right Motor forword Pin 
analogWrite(in2, 255);  //Right Motor backword Pin 
Serial.printf("%d, L\n",a);
analogWrite(in3, a); //Left Motor backword Pin 
analogWrite(in4, 255);  //Left Motor forword Pin 
}

void Stop(){ //stop
analogWrite(in1, 0); //Right Motor forword Pin 
analogWrite(in2, 0); //Right Motor backword Pin 
Serial.printf("S\n");
analogWrite(in3, 0); //Left Motor backword Pin 
analogWrite(in4, 0); //Left Motor forword Pin 
}

void Reverse(int a){  //backword
analogWrite(in1, a);  //Right Motor forward Pin 
analogWrite(in2, 255); //Right Motor backward Pin  
Serial.printf("%d, B\n",a);
analogWrite(in3, a);  //Left Motor backward Pin 
analogWrite(in4,0); //Left Motor forward Pin 

}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

  // Serial.print("X: ");
  // Serial.print(myData.a);
  // Serial.print("   Y: ");
  // Serial.println(myData.b);
  if(myData.a > 130.0){
      Forward((myData.a>200.0) ? 200:80); // move forward
      // Serial.printf("F,%d\n",(myData.a>200) ? 240:80);
    }else if (myData.b < 80.0){
      Left((myData.b<40.0) ? 200:80);
      // Serial.printf("L,%d\n",(myData.b<40.0) ? 240:80);
    }else if (myData.b > 150.0){
      Right((myData.b>200.0) ? 200:70);
      // Serial.printf("R,%d\n",(myData.b>200.0) ? 240:80);
    }else if (myData.a < 80.0){
      Reverse((myData.a<40.0) ? 200:80); // move forward
      // Serial.printf("B,%d\n",(myData.a<40) ? 240:80);
    }else{
      Stop();    // stop
      Serial.printf("stop loop");
    }
}
