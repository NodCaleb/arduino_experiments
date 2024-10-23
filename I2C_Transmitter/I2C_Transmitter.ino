#include <Wire.h>

#define OPEN_PIN  2
#define CLOSE_PIN 3
#define I2C_ADDRESS 9

uint8_t data = 0x00;

void setup() {
  Wire.begin(); // Join the I2C bus as master
  Serial.begin(9600); // Start serial communication for debugging

  // Configure pins D2 and D3 as inputs
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  // Attach interrupts
  // Attach interrupt 0 (connected to pin D2) to function handleInterrupt1
  attachInterrupt(digitalPinToInterrupt(2), handleInterrupt1, FALLING);

  // Attach interrupt 1 (connected to pin D3) to function handleInterrupt2
  attachInterrupt(digitalPinToInterrupt(3), handleInterrupt2, FALLING);
}

void loop() {

  if (data != 0x00){
    Wire.beginTransmission(I2C_ADDRESS);
    Wire.write(data);
    Wire.endTransmission();
    data = 0x00;
  } 

  delay(100); // Delay between each loop
}

// ISR for interrupt on pin D2 (INT0)
void handleInterrupt1() {
  data = 0x01;
}

// ISR for interrupt on pin D3 (INT1)
void handleInterrupt2() {
  data = 0x02;
}
