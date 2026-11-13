#include "acceleration.h"

double Acceleration::getMagnitude() const
{
   return std::sqrt(ddx * ddx + ddy * ddy);
}

void Acceleration::add(const Acceleration& rhs)
{
   ddx += rhs.ddx;
   ddy += rhs.ddy;
}