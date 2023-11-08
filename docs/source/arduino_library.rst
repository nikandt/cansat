.. _software:

Arduino library
===============

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


Sensor suite test
*****************

.. code-block:: C++

	#include "CanSat.h"
	#include <esp_now.h>
	#include "esp_wifi.h"
	#include <WiFi.h>

	uint32_t lastMessage = 0;
	uint32_t lastBlink = 0;
	#define MESSAGE_INTERVAL 100
	#define BLINK_INTERVAL 400
	#define BLINK_DURATION 100


	void ErrorLoop(String message);

	// Replace with your ground station MAC Address
	char groundsationMAC[] = {0xD4, 0xD4, 0xDA, 0x5A, 0x5A, 0x74};

	void setup() {
	  pinMode(LED, OUTPUT);
	  
	  // Set the MEAS_EN pin as output
	  pinMode(MEAS_EN, OUTPUT);
	  digitalWrite(MEAS_EN, LOW);
	  
	  uint8_t err = CanSatInit(groundsationMAC);
	  if(err)
	  {
		Serial.print("ERROR: ");
		Serial.println(err);
		ErrorLoop("Error in CanSat init");
	  }
	}




	void loop() {

	  if(lastMessage + MESSAGE_INTERVAL <= millis())
	  {
		lastMessage = millis();

		//read IMU data
		struct IMUData imudata = ReadIMU();
		printIMUData(imudata);

		// read LDR
		digitalWrite(MEAS_EN, HIGH);
		uint16_t ldr_value = analogRead(LDR);
		digitalWrite(MEAS_EN, LOW);

		// read ENV data
		struct ENVData envdata = ReadENV();
		printENVData(envdata);

		// make a String from the data
		char msg[128];
		memset(msg, 0, sizeof(msg));
		snprintf(msg, sizeof(msg), "T: %.2f C, Pressure %.2f hPa, A: %.2f %.2f %.2f  G: %.2f %.2f %.2f, LDR: %d \r\n",
		envdata.temperature, envdata.pressure, imudata.accelX, imudata.accelY, imudata.accelZ, imudata.gyroX, imudata.gyroY, imudata.gyroZ, ldr_value);
	  
		SendData(msg, strlen(msg));
	  }

	  if(lastBlink + BLINK_DURATION >= millis())
	  {
		digitalWrite(LED, HIGH);
	  }else{
		digitalWrite(LED, LOW);
	  }
	  if(lastBlink + BLINK_INTERVAL <= millis())
	  {
		lastBlink = millis();
	  }
	}


	void ErrorLoop(String message)
	{
	  int LED_status = 0;
	  while(1)
	  {
		Serial.println(message);
		digitalWrite(LED, LED_status);
		LED_status = !LED_status;
		delay(2000);
	  }
	}


For all code examples, see https://github.com/nikandt/cansat/tree/main/example%20scripts .