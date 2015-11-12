#ifndef _ACCELEROMETER_H
#define _ACCELEROMETER_H

#include <OrbitBoosterPackDefs.h>
#include "Energia.h"

#define ACCELEROMETER_MAX 512

void setup_accelerometer();
int get_accelerometer_x();
int get_accelerometer_y();
int get_accelerometer_z();

#endif