/***********************************************************************
 * Header File:
 *    Starlink : Represents a Starlink satellite
 * Author:
 *    Wesley Carlson
 * Summary:
 *    A physical Starlink satellite in orbit.
 ************************************************************************/

#pragma once

#include "satellite.h"

 /*********************************************
  * Starlink
  * Child class of Satellite representing Starlink.
  *********************************************/
class Starlink : public Satellite
{
public:
   Starlink();
   Starlink(const Position& position,
      const Velocity& velocity,
      const Angle& orientation = Angle(),
      double rotationRate = 0.0);

   void draw(ogstream& out) override;
   std::vector<SpaceObject*> breakApart() override;
};