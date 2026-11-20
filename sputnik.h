/***********************************************************************
 * Header File:
 *    Sputnik : Represents the Sputnik satellite
 * Author:
 *    Wesley Carlson
 * Summary:
 *    A physical Sputnik satellite in orbit.
 ************************************************************************/

#pragma once

#include "satellite.h"

 /*********************************************
  * Sputnik
  * Child class of Satellite representing Sputnik.
  *********************************************/
class Sputnik : public Satellite
{
public:
   Sputnik();
   Sputnik(const Position& position,
      const Velocity& velocity,
      const Angle& orientation = Angle(),
      double rotationRate = 0.0);

   void draw(ogstream& out) override;
   std::vector<SpaceObject*> breakApart() override;
};