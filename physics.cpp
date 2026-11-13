#include "physics.h"

#include <cassert>
#include <cmath>

double gravityFromDistance(double distance)
{
   assert(distance > 0.0);
   return EARTH_GRAVITATIONAL_PARAMETER / (distance * distance);
}

void computeGravity(const Position& position, double& ddx, double& ddy)
{
   const double x = position.getMetersX();
   const double y = position.getMetersY();
   const double distance = std::sqrt(x * x + y * y);

   assert(distance > 0.0);

   const double gravity = gravityFromDistance(distance);
   ddx = gravity * (-x / distance);
   ddy = gravity * (-y / distance);
}

void updatePosition(Position& position, const Velocity& velocity,
                    double ddx, double ddy, double time)
{
   const double timeSquared = time * time;

   position.addMetersX(velocity.getDX() * time + 0.5 * ddx * timeSquared);
   position.addMetersY(velocity.getDY() * time + 0.5 * ddy * timeSquared);
}

void updateVelocity(Velocity& velocity, double ddx, double ddy, double time)
{
   velocity.add(ddx, ddy, time);
}

void physicsStep(Position& position, Velocity& velocity, double time)
{
   double ddx;
   double ddy;

   computeGravity(position, ddx, ddy);
   updatePosition(position, velocity, ddx, ddy, time);
   updateVelocity(velocity, ddx, ddy, time);
}
