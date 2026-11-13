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

class Satellite : public SpaceObject
{
   friend TestSatellite;

public:
   explicit Satellite(SatelliteType type = SatelliteType::GPS);

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