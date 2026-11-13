#include "physics.h"

#include <cassert>
#include <cmath>

double gravityFromDistance(double distance)
{
   assert(distance > 0.0);
   return EARTH_GRAVITATIONAL_PARAMETER / (distance * distance);
}

Acceleration computeGravity(const Position& position)
{
   const double x = position.getMetersX();
   const double y = position.getMetersY();
   const double distance = std::sqrt(x * x + y * y);

   assert(distance > 0.0);

   const double gravity = gravityFromDistance(distance);
   return Acceleration(gravity * (-x / distance),
                       gravity * (-y / distance));
}

void updatePosition(Position& position, const Velocity& velocity,
                     const Acceleration& acceleration, double time)
{
   const double timeSquared = time * time;

   position.addMetersX(velocity.getDX() * time +
                       0.5 * acceleration.getDDX() * timeSquared);
   position.addMetersY(velocity.getDY() * time +
                       0.5 * acceleration.getDDY() * timeSquared);
}

void updateVelocity(Velocity& velocity, const Acceleration& acceleration,
                    double time)
{
   velocity.add(acceleration, time);
}

void physicsStep(Position& position, Velocity& velocity, double time)
{
   Acceleration acceleration = computeGravity(position);
   updatePosition(position, velocity, acceleration, time);
   updateVelocity(velocity, acceleration, time);
}
