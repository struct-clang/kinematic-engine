#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <math.h>

typedef struct {
    double v0x;
    double v0y;
    double v0z;

    double x0;
    double y0;
    double z0;

    double ax;
    double ay;
    double az;

    double x;
    double y;
    double z;

    double vx;
    double vy;
    double vz;
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