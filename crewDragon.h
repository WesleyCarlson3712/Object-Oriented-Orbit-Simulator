/***********************************************************************
 * Header File:
 *    CrewDragon : Represents the Crew Dragon spacecraft
 * Author:
 *    Wesley Carlson
 * Summary:
 *    A physical Crew Dragon spacecraft in orbit.
 ************************************************************************/

#pragma once

#include "satellite.h"

 /*********************************************
  * CrewDragon
  * Child class of Satellite representing Crew Dragon.
  *********************************************/
class CrewDragon : public Satellite
{
public:
   CrewDragon();
   CrewDragon(const Position& position,
      const Velocity& velocity,
      const Angle& orientation = Angle(),
      double rotationRate = 0.0);

   void draw(ogstream& out) override;
   std::vector<SpaceObject*> breakApart() override;
};