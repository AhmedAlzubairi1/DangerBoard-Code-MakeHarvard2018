#include "accel.h"

float rawx = 0;
float rawy = 0;
float rawz = 0;

void setup()
{
    accel_setup();
    Serial.begin(115200);
}

void loop()
{
  Serial.print("speed: ");
  Serial.println(get_accel());
  delay(PERIOD_MS);
}
