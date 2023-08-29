Usage
=====

.. _introduction:
.. _getting_started:
.. _setup:
.. _hardware_reference:
.. _example_scripts:


Introduction
------------

What is Cansat?
***************

The CanSat is a simulated satellite — integrated within the volume and shape of a soft drink can.

The challenge for students is to fit all the major subsystems found in a satellite,
such as power, sensors and a communication system, into the volume and shape of a soft drink can.
The CanSat is then launched by a rocket up to an altitude of approximately one kilometre.
Its mission involves carrying out a scientific experiment and a technology demonstration,
achieving a safe landing, and analysing the collected data.

Getting started
---------------

Required Software
*****************

* Arduino IDE: https://www.arduino.cc/en/software
* ESP32 pack (available from Arduino IDE's Boards Manager)
* CanSat software: https://github.com/nikandt/cansat

Required hardware
*****************

* A CanSat kit: https://holvi.com/shop/kitsat/section/satellites/

.. image:: images/product.jpg
  :width: 400
  :alt: Cansat Kit


Setup
-----

1. Download the required software (Arduino IDE): https://www.arduino.cc/en/software

2. Open Boards manager from Tools>Board>Board Manager. Type in "esp32" to the search. Install the latest ESP32 Boards package provided by Arduino. 
*Alternatively, you can install esp32 by Espressif Systems.*

3. Copy Cansat example scripts from https://github.com/nikandt/cansat/tree/main/example%20scripts to your PC.

4. Connect CanSat to your PC with a USB cable and open the led_blink/led_blink.ino file from example scripts with Arduino IDE.

5. From the top pane of Arduino IDE, choose "Select Board". Your Cansat should show up as an ESP32 device.

6. From the top pane, click "Upload" to flash the example code to your Cansat. Your Cansat board LEDs should now be blinking.


Hardware Reference
------------------

CanSat hardware pinout reference:

.. image:: images/cansat.png
  :width: 400
  :alt: Cansat Pinout

For creating custom breakouts, a board template reference:

.. image:: images/template.png
  :width: 400
  :alt: Breakout board template


Example Scripts
---------------

Receiver example
****************

.. code-block:: C++

	#include <esp_now.h>
	#include "esp_wifi.h"
	#include <WiFi.h>

	uint8_t groundsationMAC[] = {0xD4, 0xD4, 0xDA, 0x5A, 0x5A, 0x74};

	void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
	  Serial.write(incomingData, len);
	}
	 
	void setup() {
	  Serial.begin(921600);
	  WiFi.mode(WIFI_STA);
	  esp_wifi_set_mac(WIFI_IF_STA, &groundsationMAC[0]);

	  if (esp_now_init() != ESP_OK) {
		Serial.println("Error initializing ESP-NOW");
		return;
	  }
	  Serial.println("CANSAT GS Starting");
	  Serial.print("This GS MAC Address: ");
	  Serial.println(WiFi.macAddress());
	  esp_wifi_set_protocol( WIFI_IF_STA , WIFI_PROTOCOL_LR);   
	  esp_now_register_recv_cb(OnDataRecv);
	}
	 
	void loop() {

	}

For more examples, refer to https://github.com/nikandt/cansat/tree/main/example%20scripts


Trouble with setup? Leave us a message: support@kitsat.fi