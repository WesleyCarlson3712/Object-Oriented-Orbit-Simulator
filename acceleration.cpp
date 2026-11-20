/***********************************************************************
 * Source File:
 *    Acceleration : Represents acceleration in 2D space
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Implementation of acceleration calculations.
 ************************************************************************/

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