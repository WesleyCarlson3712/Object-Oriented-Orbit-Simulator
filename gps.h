/***********************************************************************
 * Header File:
 *    GPS : Represents a GPS satellite
 * Author:
 *    Wesley Carlson
 * Summary:
 *    A physical GPS satellite in orbit.
 ************************************************************************/

#pragma once

#include "satellite.h"

 /*********************************************
  * GPS
  * Child class of Satellite representing a GPS satellite.
  *********************************************/
class GPS : public Satellite
{
public:
   GPS();
   GPS(const Position& position,
      const Velocity& velocity,
      const Angle& orientation = Angle(),
      double rotationRate = 0.0);

   void update(double time) override;
   void draw(ogstream& out) override;
   std::vector<SpaceObject*> breakApart() override;
};