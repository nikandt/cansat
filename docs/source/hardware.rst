Hardware
========

.. _pinout:

Pinout
------

.. list-table:: User pins
   :widths: 25 25 50
   :header-rows: 1

   * - Pin name
     - Pin number
     - Description
     - Pin type or subsystem
   * - SCL
     - 1
     - SCL, I2C line
     - Sensor Suite
   * - SDA
     - 2
     - SDA, I2C line
	 - Sensor suite
   * - GPIO12
     - 3
     - Digital I/O
	 - Unallocated digital I/O
   * - SCLK
     - 4
     - Clock select, SPI line
	 - SD Card
   * - MISO
     - 5
     - Main input secondary output, SPI line
	 - SD Card
   * - MOSI
     - 6
     - Main output secondary input, SPI line
	 - SD Card
   * - TX
     - 7
     - Transmission, UART line
	 - Unallocated
   * - RC
     - 7
     - Reception, UART line
	 - Unallocated

.. _board_layout:

Board layout
------------

CanSat hardware pinout reference:

.. image:: images/cansat.png
  :width: 400
  :alt: Cansat Pinout

For creating custom breakouts, a board template reference:

.. image:: images/template.png
  :width: 400
  :alt: Breakout board template