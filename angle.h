/***********************************************************************
 * Header File:
 *    Angle : Represents an angle
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Represents an angle in radians with degree and component conversions.
 ************************************************************************/

#pragma once

#include <cmath>

class TestAngle;

/*********************************************
 * Angle
 * Represents an angle. Internally, angles are
 * stored in radians.
 *********************************************/
class Angle
{
   friend TestAngle;

public:
   static constexpr double PI = 3.14159265358979323846;

   Angle() : radians(0.0) {}
   explicit Angle(double radians) : radians(radians) {}

   double getRadians() const { return radians; }
   double getDegrees() const;
   double getDx() const;
   double getDy() const;

   void setRadians(double radians) { this->radians = radians; }
   void setDegrees(double degrees);
   void setDxDy(double dx, double dy);

   Angle& add(double delta);

private:
   double radians;
};
