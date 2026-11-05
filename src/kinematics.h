#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <math.h>

typedef struct {
    double v0x, v0y, v0z;
    double x0, y0, z0;
    double ax, ay, az;
    
    double x, y, z;
    double vx, vy, vz;
} Body;

typedef enum {
    X_AXIS,
    Y_AXIS,
    Z_AXIS
} Axis;

double position(double t, Body *body, Axis axis);
double velocity(double t, Body *body, Axis axis);
double landingTime(Body *body);
double velocityAfterBounce(double e, double v);
int bounces(double currentV, double restitution, double minV);

#endif