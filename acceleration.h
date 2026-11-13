#pragma once

#include <cmath>

class TestAcceleration;

class Acceleration
{
   friend TestAcceleration;

public:
   Acceleration() : ddx(0.0), ddy(0.0) {}
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) {}

   double getDDX() const { return ddx; }
   double getDDY() const { return ddy; }
   double getMagnitude() const;

   void setDDX(double ddx) { this->ddx = ddx; }
   void setDDY(double ddy) { this->ddy = ddy; }

   void add(const Acceleration& rhs);

private:
   double ddx;
   double ddy;
};