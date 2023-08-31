Software
========

.. _software:

Software
--------

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