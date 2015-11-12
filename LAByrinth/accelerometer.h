#ifndef _ACCELEROMETER_H
#define _ACCELEROMETER_H

#include <OrbitBoosterPackDefs.h>
#include "Energia.h"

#define ACCELEROMETER_MAX 511
#define ACCELEROMETER_MIN -512

/*
 * Here is how the accelerometer works:
 *                         +y
 *                          ^
 *                          |
 *       **************************************
 *       *         ******************         *
 *       *         *                *         *
 *       *         ******************         *
 *       *                                    *
 * -x <- *                                    * -> +x
 *       *                                    *
 *       *                                    *
 *       *                                    *
 *       *                                    *
 *       **************************************
 *                          |
 *                          v
 *                         -y
 *
 * Into screen:   +z
 * Out of screen: -z
 *
 */
 
void setup_accelerometer();
int get_accelerometer_x();
int get_accelerometer_y();
int get_accelerometer_z();

#endif