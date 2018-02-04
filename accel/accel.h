#ifndef ACCEL_H
#define ACCEL_H

#include "MMA7660.h"

// you know the drill. I'm tired, don't feel like writing this correctly, don't include in more than one place yadda yadda yadda
MMA7660 acc;

// we're really only gonna need one axis when we're done...
float ax,ay,az,ax1=0,ay1=0,az1=0,vx=0,vy=0,vz=0;
void read_accel() {
  acc.getAcceleration(&ax,&ay,&az);
  vx = vx + (.05 * (ax1 + ax)/20.0);
  vy = vy + (.05 * (ay1 + ay)/20.0);
  vz = vz + (.05 * (az1 + az)/20.0);
  ax1 = ax;
  ay1 = ay;
  az1 = az;
}

void accel_setup() {
  acc.init();
}

float get_speed() {
  return(vy);
}

#endif
