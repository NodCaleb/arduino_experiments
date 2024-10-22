#include <Wire.h>
#define I2C_ADDRESS 9

void setup() {
  Wire.begin(I2C_ADDRESS); // Join I2C bus with address #8
  Wire.onReceive(receiveEvent); // Register the receive event
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  delay(100); // Just keep looping
}

// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) {
    char c = Wire.read(); // Receive each byte
    Serial.print(c); // Print received data for debugging
  }
  Serial.println(); // Newline after data is printed
}