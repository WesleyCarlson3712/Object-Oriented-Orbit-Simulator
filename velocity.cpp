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

void Velocity::add(const Acceleration& acceleration, double time)
{
   dx += acceleration.getDDX() * time;
   dy += acceleration.getDDY() * time;
}
