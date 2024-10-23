#include <Wire.h>
#define I2C_ADDRESS 9
#define LED_PIN 13

uint8_t ledState = 0;

void setup() {
  Wire.begin(I2C_ADDRESS); // Join I2C bus with address #8
  Wire.onReceive(receiveEvent); // Register the receive event
  Serial.begin(9600); // Start serial communication for debugging
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  
  digitalWrite(LED_PIN, ledState);

  delay(100); // Just keep looping
}

// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) {
    uint8_t c = Wire.read();
    if (c == 0x01) ledState = 1;
    if (c == 0x02) ledState = 0;
  }
}