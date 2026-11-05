#include <stdio.h>
#include "kinematics.h"

int main() {
    Body ball;

    ball.v0y = 20;
    ball.v0x = 10;
    ball.v0z = 10;

    ball.x0 = 0;
    ball.y0 = -10;
    ball.z0 = 0;

    ball.ax = 0;
    ball.ay = -9.81; // Earth
    ball.az = 0;

    ball.x = 0;
    ball.y = 0;
    ball.z = 0;

    ball.vx = 0;
    ball.vy = 0;
    ball.vz = 0;

    const double landing = landingTime(&ball); // Time when ball lands
    const double dt = 0.1;
    const double restitution = 0.8;
    const double minVelocity = 0.1; // m/s

    for (double timer = 0; timer < landing; timer += dt) {
        // Calculating position and velocity for current time
        ball.x = position(timer, &ball, X_AXIS);
        ball.y = position(timer, &ball, Y_AXIS);
        ball.z = position(timer, &ball, Z_AXIS);

        ball.vx = velocity(timer, &ball, X_AXIS);
        ball.vy = velocity(timer, &ball, Y_AXIS);
        ball.vz = velocity(timer, &ball, Z_AXIS);

        printf("t=%f | x=%f | vX=%f | y=%f | vY=%f | z=%f | vZ=%f\n",
            timer, ball.x, ball.vx, ball.y, ball.vy, ball.z, ball.vz
        );
    }

    // Data when ball will land
    printf("t=%f | x=%f | vX=%f | y=0 | vY=%f | z=%f | vZ=%f\n",
                landing,                          // Landing time
                position(landing, &ball, X_AXIS), // X axis position
                velocity(landing, &ball, X_AXIS), // X axis velocity
                velocity(landing, &ball, Y_AXIS), // Y axis velocity
                position(landing, &ball, Z_AXIS), // Z axis position
                velocity(landing, &ball, Z_AXIS)  // Z axis velocity
            );

    // Bouncing

    int extraBounces = bounces(
        velocity(landing, &ball, Y_AXIS),
        restitution,
        minVelocity
    );

    printf("With %d extra bounces\n", extraBounces);

    return 0;
}