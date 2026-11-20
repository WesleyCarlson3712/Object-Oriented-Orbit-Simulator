/***********************************************************************
 * Source File:
 *    Angle : Represents an angle
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Methods for the Angle class
 ************************************************************************/

#include "angle.h"
#include <cmath>

/*********************************************
 * ANGLE : GET DEGREES
 * Return the angle converted to degrees.
 *********************************************/
double Angle::getDegrees() const
{
   return radians * 180.0 / PI;
}

/*********************************************
 * ANGLE : GET DX
 * Return the horizontal component of the angle.
 *********************************************/
double Angle::getDx() const
{
   return std::cos(radians);
}

/*********************************************
 * ANGLE : GET DY
 * Return the vertical component of the angle.
 *********************************************/
double Angle::getDy() const
{
   return std::sin(radians);
}

/*********************************************
 * ANGLE : SET DEGREES
 * Set the angle in degrees, converted to radians.
 *********************************************/
void Angle::setDegrees(double degrees)
{
   radians = degrees * PI / 180.0;
}

/*********************************************
 * ANGLE : SET DX DY
 * Set the angle based on horizontal and vertical components.
 *********************************************/
void Angle::setDxDy(double dx, double dy)
{
   radians = std::atan2(dy, dx);
}

/*********************************************
 * ANGLE : ADD
 * Add a delta angle in radians to the current angle.
 *********************************************/
Angle& Angle::add(double delta)
{
   radians += delta;
   return *this;
}

