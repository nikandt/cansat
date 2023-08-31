Hardware
========

.. _power:

Power
-----

During development, the CanSat kit can be powered on with a USB Micro - Type A cable.

During flight, an external power source must be used. Plug in three AAA alkaline batteries to the Cansat's bottom side.

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

For creating custom breakouts, a board template reference:

.. image:: images/template.png
  :width: 400
  :alt: Breakout board template