#pragma once
#include <cmath>
#include "angle.h"

class TestVelocity;

class Velocity
{
   friend TestVelocity;

public:
   Velocity() : dx(0.0), dy(0.0) {}
   Velocity(double dx, double dy) : dx(dx), dy(dy) {}

   double getDX() const { return dx; }
   double getDY() const { return dy; }
   double getSpeed() const;
   Angle getAngle() const;

   void setDX(double dx) { this->dx = dx; }
   void setDY(double dy) { this->dy = dy; }
   void addDX(double dx) { this->dx += dx; }
   void addDY(double dy) { this->dy += dy; }

   void add(double ddx, double ddy, double time);

private:
   double dx;
   double dy;
};
