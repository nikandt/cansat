.. _arduino_library:

Arduino library
===============

This library provides easy access to the hardware resources of the CanSat NeXT board. The library supports both the satellite and the receiver radio.

.. _installation:

Installation
------------

1. Install the Arduino IDE

* Download and install the Arduino IDE from the official website if you haven’t already: https://www.arduino.cc/en/software

2. Install ESP32 Support

* Open the Arduino IDE.
* Navigate to Tools->Board->Boards Manager.
* In the search bar, type in "ESP32" and find the option provided by Espressif.
* Click "install" to add support to your Arduino IDE.

3. Install the CanSat NeXT Library
	
* In the Arduino IDE, go to Sketch -> Include Library -> Manage Libraries.
* In the search bar, type "CanSatNeXT" and find the corresponding library.
* Click "Install" to install the library. If the Arduino IDE asks if you want to install with dependencies - click yes.
* Alternatively, you can manually add the library by downloading this repository: https://github.com/netnspace/CanSatNeXT_library and saving it into the Arduino libraries folder on your computer.


.. _example_codes:

Example codes
-------------

To explore the use of the various hardware resources, go to File -> Examples -> CanSatNeXT in the Arduino IDE.

See also CanSat GNSS library for use of the CanSat NeXT GPS module: https://github.com/netnspace/CanSatNeXT_GNSS

Send data example
*****************

.. code-block:: C++

	/*
	  This example shows how data can be sent from the satellite to the groundstation. The same functions work the other way around as well, and can be used to send data to the satellite from the groundstation.

	  Caution - You should always have an antenna in a radio system before transmitting anything. Make sure the antenna is plugged in before sending data via the radio.
	*/

	#include "CanSatNeXT.h"

	// This is the address of the groundstation we will send data to.
	uint8_t groundsationMAC[] = {0xA8, 0x42, 0xE3, 0xDA, 0x86, 0x48};

	void setup() {

	  // Initialize serial with baud rate 115200
	  Serial.begin(115200);

	  // Initialize CanSatNeXT systems. Calling this function with the MAC address as a parameter enables the radio.
	  CanSatInit(groundsationMAC);
	}

	void loop() {
	  
	  // Let's use a random number to mock a sensor
	  uint8_t value = random(255);

	  // The data can be sent either as a string or as binary data.

	  // Send a simple message
	  sendData("This is our message.");

	  // To send a variable, we need to convert it into a string
	  sendData(String(value));

	  // Alternatively, we can send the value as binary data. This is more efficient, but can be tricky.
	  char msg[1];
	  msg[0] = value;
	  sendData(msg, sizeof(msg));
	  
	  
	  delay(1000);
	}


External SPI example
********************

.. code-block:: C++

	/*
	  This example shows how to use the SPI from the extension header to connect to an
	  external SPI device. Essentially, it is used just like normally. The pins just
	  need to be modified based on the hardware setup. This example uses an external
	  analog-to-digital converter MCP3008, but the same approach works for any other SPI
	  device as well. This example uses Adafruit MCP3008 library to communicate with the MCP3008.
	  The code is modified from the Adafruit example provided with the library.
	*/

	#include <Adafruit_MCP3008.h>

	// Include CanSatNeXT to get the pin definitions
	#include <CanSatNeXT.h>

	Adafruit_MCP3008 adc;

	int count = 0;


	void setup() {
	  Serial.begin(9600);
	  while (!Serial);

	  Serial.println("MCP3008 simple test.");

	  // Hardware SPI (specify CS, use any available digital)
	  // Can use defaults if available, ex: UNO (SS=10) or Huzzah (SS=15)
	  
	 /* *'''''''''''''''''
	 This is the only modification to the library example
	 */
	  // Use SPI pins. Chip select can be any GPIO pin, this time we use pin 12.
	  adc.begin(SPI_CLK, SPI_MOSI, SPI_MISO, 12);
	// ^^^^^^^^^^^^^^

	  // Feather 32u4 (SS=17) or M0 (SS=16), defaults SS not broken out, must specify
	  //adc.begin(10);  

	  // Software SPI (specify all, use any available digital)
	  // (sck, mosi, miso, cs);
	  //adc.begin(13, 11, 12, 10);
	}


	void loop() {
	  for (int chan=0; chan<8; chan++) {
		Serial.print(adc.readADC(chan)); Serial.print("\t");
	  }
	  Serial.print("["); Serial.print(count); Serial.println("]");
	  count++;
	  
	  delay(100);
	}