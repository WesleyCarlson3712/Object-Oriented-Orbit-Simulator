/***********************************************************************
 * Header File:
 *    Thrust : Represents thruster activation and acceleration
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Represents the propulsion thrusters of a spacecraft.
 ************************************************************************/

#pragma once

#include "acceleration.h"
#include "angle.h"

class TestThrust;
class TestShip;

/*********************************************
 * Thrust
 * Represents the propulsion thrusters of a ship.
 *********************************************/
class Thrust
{
   friend TestThrust;
   friend TestShip;

public:
   Thrust();

   void activate() { active = true; }
   void deactivate() { active = false; }
   bool isActive() const { return active; }

   void setMagnitude(double magnitude) { this->magnitude = magnitude; }
   double getMagnitude() const { return magnitude; }

   Acceleration getAcceleration(const Angle& direction) const;

private:
   bool active;
   double magnitude;
};