Hardware
========

.. _power:

Power
-----

During development, the CanSat kit can be powered on with a USB Micro - Type A cable.

During flight, an external power source must be used. Plug in three AAA alkaline batteries to the Cansat's bottom side.

.. _hardware_interface:

Interface
---------

CanSat hardware interface

.. image:: images/hw_interface.png
  :width: 400
  :alt: Cansat Hardware Interface
  
  
1. User pins, top
2. User pins, bottom
3. USB Micro port
4. Reset Switch
5. SD Card
6. Power Switch
7. Antenna
8. Thermistor
9. AAA Battery holder (on the backside of the board).


.. _pinout:

Pinout
------

.. list-table:: User pins, top
   :widths: 20 20 40 20
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
     - Sensor Suite
   * - GPIO12
     - 3
     - Digital I/O
     - Unallocated
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
     - 8
     - Reception, UART line
     - Unallocated


.. list-table:: User pins, bottom
   :widths: 20 20 40 20
   :header-rows: 1

   * - Pin name
     - Pin number
     - Description
     - Pin type or subsystem
   * - GND
     - 9
     - Ground, power line
     - Power
   * - +3V3
     - 10
     - +3V3, power line
     - Power
   * - GPIO14
     - 11
     - Digital I/O
     - Unallocated
   * - GPIO25
     - 12
     - Digital I/O
     - Unallocated
   * - GPIO26
     - 13
     - Digital I/O
     - Unallocated
   * - GPIO27
     - 14
     - Digital I/O
     - Unallocated
   * - GPIO32
     - 15
     - Digital I/O
     - Unallocated
   * - GPIO33
     - 16
     - Digital I/O
     - Unallocated

.. _board_layout:

Board layout
------------

CanSat hardware layout reference:

.. image:: images/cansat.png
  :width: 400
  :alt: Cansat Layout

For creating custom payloads, a board template reference:

.. image:: images/template.png
  :width: 400
  :alt: Breakout board template