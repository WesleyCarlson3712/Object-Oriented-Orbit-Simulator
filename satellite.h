/***********************************************************************
 * Header File:
 *    Satellite : Abstract base class for satellites orbiting the Earth
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Defines the Satellite abstract base class.
 ************************************************************************/

#pragma once

#include <vector>
#include "spaceObject.h"

class TestSatellite;

/*********************************************
 * Satellite
 * An abstract physical satellite that orbits the Earth.
 * Subtypes specialize draw() and breakApart().
 *********************************************/
class Satellite : public SpaceObject
{
   friend TestSatellite;

public:
   Satellite();
   Satellite(const Position& position,
             const Velocity& velocity,
             const Angle& orientation,
             double rotationRate);

   virtual ~Satellite() = default;

   void update(double time) override;
   void draw(ogstream& out) override = 0;
   std::vector<SpaceObject*> breakApart() override = 0;

   void makeDefunct();
   bool isDefunct() const;

protected:
   void beginUncontrolledSpin();

   bool defunct;
   double uncontrolledRotationRate;
};