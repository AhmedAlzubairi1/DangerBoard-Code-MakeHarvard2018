#include "accel.h"

float rawx = 0;
float rawy = 0;
float rawz = 0;

void setup()
{
    accel_setup();
    pinMode(4, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
  float accel = get_accel();
  if( accel < 0.3 && accel > -0.3 ) {
    digitalWrite(4, LOW);
  } else {
    digitalWrite(4, HIGH);
  }
  delay(PERIOD_MS);
}
