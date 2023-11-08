.. _gnss:

CanSat GNSS module
==================

CanSat comes with a separate library for the GNSS module:
https://github.com/netnspace/CanSatNeXT_GNSS

This library extends CanSat NeXT to add support for the GNSS board. This library prioritizes ease-of-use, and only has basic functionalities such as getting location and time from the GNSS. For users looking for more advanced GNSS features, the excellent SparkFun_u-blox_GNSS_Arduino_Library might be a better choice. This library is actually just a wrapper for that library, just making all configurations with CanSat operations in mind.

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

3. Install the CanSatNeXT_GNSS Library
	
* In the Arduino IDE, go to Sketch -> Include Library -> Manage Libraries.
* In the search bar, type "CanSatNeXT_GNSS" and find the corresponding library.
* Click "Install" to install the library. If the Arduino IDE asks if you want to install with dependencies - click yes.
* Alternatively, you can manually add the library by downloading this repository: https://github.com/netnspace/CanSatNeXT_GNSS and saving it into the Arduino libraries folder on your computer.

4. Connect the GPS module

* Turn power off from CanSat NeXT
* Plug in the GNSS board, making sure all the pins are attached
* Turn power on. The GNSS module will immediately start looking for a location fix.

5. Get Started with the CanSatNeXT

* Check examples for how to read the location, go to File -> Examples -> CanSatNeXT_GPS in the Arduino IDE.

.. _example_codes:

Example codes
-------------

To explore the use of the various hardware resources, go to File -> Examples -> CanSatNeXT_GNSS in the Arduino IDE.

Read position example
*********************

.. code-block:: C++

	/*
		This example shows how to use CanSatNeXT_GNSS library to read latitude, longitude, altitude and time
		from the GNSS module. Latitude and longitude are in degrees and the altitude is in meters. The timestamp
		is in unix time, i.e. seconds elapsed since 1st of January 1970 on midnight UTC.
	*/

	#include "CanSatNeXT_GNSS.h"

	// Declare variables to hold latitude, longitude and altitude.
	float latitude = 0, longitude = 0, altitude = 0;
	long GNSSTimer = 0;

	void setup()
	{
		// Initialize serial so we can print information
		Serial.begin(115200);

		// Initialize the GNSS module. This sets correct settings etc.
		if(!GNSS_init()){
			Serial.println("Module not found");
			return;
		}

		// Note on the GNSS initialization: By default the GNSS is told to assume it is stationary on the height axis
		// You can change this behavior by initializing the GNSS like this: GNSS_init(DYNAMIC_MODEL_AIRBORNE);
	}

	void loop()
	{
		// Check GPS every 1 seconds - Note: Trying to read the position more than 10 times per second will lead to timing issues
		if (millis() - GNSSTimer > 1000)
		{
			GNSSTimer = millis(); //Update the timer

			// We want to update the position only when we have good satellite fixes.
			// getSIV() returns the number of satellites we are receiving from. Let's only update the position
			// if we have fix to three or more satellites. Less than three can't create a unique position solution.
			if(getSIV()>=3)
			{
			  // Read new position to the variables
			  readPosition(latitude, longitude, altitude);
			  // Read current unix timestamp
			  uint32_t unixTime = getTime();

			  // Print the readings
			  Serial.print("Latitude: ");
			  Serial.print(latitude, 5); // Print with five decimal places
			  Serial.print(", Longitude: ");
			  Serial.print(longitude, 5);
			  Serial.print(", Altitude: ");
			  Serial.print(altitude);
			  Serial.print(", Unix timestamp:");
			  Serial.print(unixTime);
			  Serial.print(", Millis: ");
			  Serial.println(millis());
			}else{
			  Serial.println("No fix");
			}
		}
	}