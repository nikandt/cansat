#include "CanSatPins.h"

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Set the MEAS_EN pin as output
  pinMode(MEAS_EN, OUTPUT);

  // Set the MEAS_EN pin to HIGH, enabling the LDR
  digitalWrite(MEAS_EN, HIGH);

  // The LDR is an analog sensor, so we don't need to set its pin mode
}

void loop() {
  // Read the value from the LDR
  int ldrValue = analogRead(LDR);
  
  // Print the value to the serial monitor
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);
  
  // Delay for a while before the next reading
  delay(100);
}
