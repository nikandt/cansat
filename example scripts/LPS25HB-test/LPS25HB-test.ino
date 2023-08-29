#include <Wire.h>
#include <LPS.h>
#include "CanSatPins.h"

LPS ps;
byte address = 0b1011100;


void printByte(byte val)
{
  Serial.print("0x");
  Serial.print(val < 16 ? "0" : "");
  Serial.print(val, HEX);
}

byte readReg(int reg)
{
  byte value;

  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.endTransmission(false); // restart
  Wire.requestFrom(address, (byte)1);
  value = Wire.read();
  return value;
}

void setup()
{
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);

  if (!ps.init()) // requires setting the device address manually
  {
    Serial.println("Failed to autodetect pressure sensor!");
    while (1);
  }
  ps.enableDefault();
  for(int i = 0; i<0x3A; i++)
  {
    byte val = readReg(i);
    printByte(i);
    Serial.print("  ");
    printByte(val);
    Serial.println("");
    delay(10);
  }
}

void loop()
{
  float pressure = ps.readPressureMillibars();
  float altitude = ps.pressureToAltitudeMeters(pressure);
  float temperature = ps.readTemperatureC();
  
  Serial.print("p: ");
  Serial.print(pressure);
  Serial.print(" mbar\ta: ");
  Serial.print(altitude);
  Serial.print(" m\tt: ");
  Serial.print(temperature);
  Serial.println(" deg C");

  delay(5000);
}
