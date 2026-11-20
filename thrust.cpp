/***********************************************************************
 * Source File:
 *    Thrust : Represents thruster activation and acceleration
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Implementation of spacecraft thruster calculations.
 ************************************************************************/

#include "thrust.h"
#include <cmath>

 /*********************************************
  * Thrust : CONSTRUCTOR
  * Defaults to inactive with standard 2.0 m/s^2 thrust.
  *********************************************/
Thrust::Thrust() :
   active(false),
   magnitude(2.0)
{
}

/*********************************************
 * Thrust : GET ACCELERATION
 * Compute directional acceleration produced by thrust.
 * When rotation is 0, the ship faces +Y (up), so:
 * ddx = magnitude * sin(rotation)
 * ddy = magnitude * cos(rotation)
 *********************************************/
Acceleration Thrust::getAcceleration(const Angle& direction) const
{
   if (!active)
      return Acceleration(0.0, 0.0);

   double radians = direction.getRadians();
   double ddx = magnitude * std::sin(radians);
   double ddy = magnitude * std::cos(radians);

   return Acceleration(ddx, ddy);
}