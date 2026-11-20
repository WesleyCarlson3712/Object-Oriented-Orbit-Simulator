/***********************************************************************
 * Header File:
 *    Hubble : Represents the Hubble Space Telescope
 * Author:
 *    Wesley Carlson
 * Summary:
 *    A physical Hubble telescope in orbit.
 ************************************************************************/

#pragma once

#include "satellite.h"

 /*********************************************
  * Hubble
  * Child class of Satellite representing Hubble.
  *********************************************/
class Hubble : public Satellite
{
public:
   Hubble();
   Hubble(const Position& position,
      const Velocity& velocity,
      const Angle& orientation = Angle(),
      double rotationRate = 0.0);

   void draw(ogstream& out) override;
   std::vector<SpaceObject*> breakApart() override;
};