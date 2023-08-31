.. _software:

Software
========

.. _example_codes:

Example codes
-------------

LED Blink example
*****************

.. code-block:: C++

	const int ledPin = 5;

	void setup() {
	  // put your setup code here, to run once:
	  pinMode(ledPin, OUTPUT);
	  Serial.begin(115200);
	}

	void loop() {
	  // put your main code here, to run repeatedly:
	  Serial.println("asdf");
	  digitalWrite(ledPin, HIGH);
	  delay(50);
	  digitalWrite(ledPin, LOW);
	  delay(950);
	}


LDR Test Example
****************

.. code-block:: C++

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


For additional code examples, see https://github.com/nikandt/cansat/tree/main/example%20scripts .