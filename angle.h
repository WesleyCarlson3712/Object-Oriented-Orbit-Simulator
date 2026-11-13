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
   double getDegrees() const { return radians * 180.0 / PI; }
   double getDx() const { return std::cos(radians); }
   double getDy() const { return std::sin(radians); }

   void setRadians(double radians) { this->radians = radians; }
   void setDegrees(double degrees)
   {
      radians = degrees * PI / 180.0;
   }
   void setDxDy(double dx, double dy) { radians = std::atan2(dy, dx); }

   Angle& add(double delta)
   {
      radians += delta;
      return *this;
   }

private:
   double radians;
};
