#include "kinematics.h"

double position(double t, Body *body, Axis axis) {
    switch (axis) {
    case X_AXIS:
        return body->x0 + body->v0x * t + body->ax*t*t / 2;

    case Y_AXIS:
        return body->y0 + body->v0y * t + body->ay*t*t / 2;

    case Z_AXIS:
        return body->z0 + body->v0z * t + body->az*t*t / 2;
    
    default:
        return 0;
    }
}

double velocity(double t, Body *body, Axis axis) {
    switch (axis) {
    case X_AXIS:
        return body->v0x + body->ax*t;

    case Y_AXIS:
        return body->v0y + body->ay*t;

    case Z_AXIS:
        return body->v0z + body->az*t;

    default:
        return 0;
    }
}

double landingTime(Body *body) {
    const double D = pow(body->v0y, 2) - 2 * body->ay * body->y0;

    if (body->ay == 0) {
        return 0;
    } else {
        double x1 = (-(body->v0y) - sqrt(D)) / body->ay;
        double x2 = (-(body->v0y) + sqrt(D)) / body->ay;

        if (x1 > x2) {
            return x1;
        } else {
            return x2;
        }
    }
}

double velocityAfterBounce(double e, double v) {
    return -e * v;
}

int bounces(double currentV, double restitution, double minV) {
    return ceil(
        log(minV / fabs(currentV)) / log(restitution)
    );
}