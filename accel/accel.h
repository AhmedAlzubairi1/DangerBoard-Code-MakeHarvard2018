#ifndef ACCEL_H
#define ACCEL_H

#include "MMA7660.h"

#define PERIOD_MS 25
#define THRESH 0.2

// you know the drill. I'm tired, don't feel like writing this correctly, don't include in more than one place yadda yadda yadda
MMA7660 acc;

// we're really only gonna need one axis when we're done...
// plot twist this doesn't work!
float ax, ay, az;
/*
float vx=0,vy=0,vz=0;
void read_accel() {
  acc.getAcceleration(&ax,&ay,&az);
  // convert g to ft/s^2
  ax = ax > THRESH || ax < -THRESH ? ax * 32 : 0;
  ay = ay > THRESH || ay < -THRESH ? ay * 32 : 0;
  az = az > THRESH || az < -THRESH ? az * 32 : 0;

  // integrate...ish
  vx += ax * (PERIOD_MS / 1000.0);
  vy += ay * (PERIOD_MS / 1000.0);
  vz += az * (PERIOD_MS / 1000.0);
}
*/

void accel_setup() {
  acc.init();
}

/*
float get_speed() {
  return(vy);
}
*/

float get_accel() {
  acc.getAcceleration(&ax,&ay,&az);
  // convert g to ft/s^2
  ax = ax > THRESH || ax < -THRESH ? ax * 32 : 0;
  ay = ay > THRESH || ay < -THRESH ? ay * 32 : 0;
  az = az > THRESH || az < -THRESH ? az * 32 : 0;

  return ay;
}

#endif
