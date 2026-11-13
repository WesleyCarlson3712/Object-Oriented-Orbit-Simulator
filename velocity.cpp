#include "velocity.h"

double Velocity::getSpeed() const
{
   return std::sqrt(dx * dx + dy * dy);
}

Angle Velocity::getAngle() const
{
   Angle angle;
   angle.setDxDy(dx, dy);
   return angle;
}

void Velocity::add(double ddx, double ddy, double time)
{
   dx += ddx * time;
   dy += ddy * time;
}
