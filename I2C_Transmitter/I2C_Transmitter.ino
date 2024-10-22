#include <Wire.h>

#define OPEN_PIN  2
#define CLOSE_PIN 3
#define I2C_ADDRESS 9

void setup() {
  Wire.begin(); // Join the I2C bus as master
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  // Send data to Slave 1 (address 0x08)
  Wire.beginTransmission(I2C_ADDRESS); // Start communication with Slave 1
  Wire.write("Hello, Slave 1"); // Send data
  Wire.endTransmission(); // End communication

  delay(500); // Wait before sending data again

  // Request data from Slave 2 (address 0x09)
  // Wire.requestFrom(0x09, 13); // Request 13 bytes of data from Slave 2

  // while (Wire.available()) {
  //   char c = Wire.read(); // Receive each byte
  //   Serial.print(c); // Print the received data to Serial Monitor
  // }

  delay(1000); // Delay between each loop
}