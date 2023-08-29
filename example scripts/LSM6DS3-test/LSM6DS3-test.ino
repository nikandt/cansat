#include <Wire.h>
#include <LSM6.h>
#include "CanSatPins.h"

LSM6 imu;

char report[80];

void setup()
{
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);

  if (!imu.init()) // requires setting device type and last bit manually. 
  {
    Serial.println("Failed to detect and initialize IMU!");
    while (1);
  }
  imu.enableDefault();
}

void loop()
{
  imu.read();

  snprintf(report, sizeof(report), "A: %6d %6d %6d    G: %6d %6d %6d",
    imu.a.x, imu.a.y, imu.a.z,
    imu.g.x, imu.g.y, imu.g.z);
  Serial.println(report);

  delay(100);
}
