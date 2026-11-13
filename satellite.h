#pragma once

#include <vector>

#include "spaceObject.h"

class TestSatellite;

enum class SatelliteType
{
   SPUTNIK,
   GPS,
   HUBBLE,
   CREW_DRAGON,
   STARLINK
};

/*********************************************
 * Satellite
 * A physical satellite that orbits the Earth.
 *********************************************/
class Satellite : public SpaceObject
{
   friend TestSatellite;

public:
   Satellite(SatelliteType type,
             const Position& position,
             const Velocity& velocity,
             const Angle& orientation,
             double rotationRate);

   void update(double time) override;
   void draw(ogstream& out) override;
   std::vector<SpaceObject*> breakApart() override;

   void makeDefunct();
   bool isDefunct() const;

private:
   void beginUncontrolledSpin();

   SatelliteType type;
   bool defunct;
   double uncontrolledRotationRate;
};