#include "velocity.h"

double Velocity::getSpeed() const
{
   return std::sqrt(dx * dx + dy * dy);
}

void Velocity::add(double ddx, double ddy, double time)
{
   dx += ddx * time;
   dy += ddy * time;
}
