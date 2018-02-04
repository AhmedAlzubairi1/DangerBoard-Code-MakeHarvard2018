#include "accel.h"

void setup()
{
    accel_setup();
    Serial.begin(115200);
}

void loop()
{
  read_accel();
  Serial.println(get_speed());
}
