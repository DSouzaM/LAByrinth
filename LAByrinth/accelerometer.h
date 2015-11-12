#ifndef _ACCELEROMETER_H
#define _ACCELEROMETER_H

#include <OrbitBoosterPackDefs.h>
#include "Energia.h"

#define ACCELEROMETER_MAX 512

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
 *                          V
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