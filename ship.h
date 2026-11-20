/***********************************************************************
 * Header File:
 *    Ship : Represents the player-controlled spacecraft
 * Author:
 *    Wesley Carlson
 * Summary:
 *    A controllable physical spacecraft that orbits the Earth.
 ************************************************************************/

#pragma once

#include <vector>
#include "spaceObject.h"
#include "thrust.h"

class TestShip;

/*********************************************
 * Ship
 * Player-controlled spacecraft in orbit.
 *********************************************/
class Ship : public SpaceObject
{
   friend TestShip;

public:
   Ship();
   Ship(const Position& position,
      const Velocity& velocity,
      const Angle& orientation = Angle(),
      double rotationRate = 0.0);

   void setThrust(bool active);
   bool isThrusting() const;

   void turn(double amount);
   void thrust(double time);
   void fire();

   void update(double time) override;
   void draw(ogstream& out) override;
   std::vector<SpaceObject*> breakApart() override;

private:
   Thrust engine;
};