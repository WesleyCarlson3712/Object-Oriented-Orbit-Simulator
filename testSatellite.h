#pragma once

#include <cmath>

#include "satellite.h"
#include "unitTest.h"

class TestSatellite : public Satellite, public UnitTest
{
public:
   TestSatellite() :
      Satellite(SatelliteType::GPS,
                Position(0.0, 42164000.0),
                Velocity(-3100.0, 0.0),
                Angle(-Angle::PI / 2.0),
                0.0)
   {
   }

   void run()
   {
      construct_default();
      update();
      makeDefunct();
      testBreakApart();

      report("Satellite");
   }

private:
   void construct_default()
   {
      Satellite satellite(
         SatelliteType::GPS,
         Position(0.0, 42164000.0),
         Velocity(-3100.0, 0.0),
         Angle(-Angle::PI / 2.0),
         0.0);

      assertUnit(satellite.type == SatelliteType::GPS);
      assertUnit(!satellite.defunct);
      assertEquals(satellite.position.getMetersX(), 0.0);
      assertEquals(satellite.position.getMetersY(), 42164000.0);
      assertEquals(satellite.velocity.getDX(), -3100.0);
      assertEquals(satellite.velocity.getDY(), 0.0);
      assertEquals(satellite.orientation.getRadians(), -Angle::PI / 2.0);
   }

   void update()
   {
      Satellite satellite(
         SatelliteType::GPS,
         Position(0.0, 42164000.0),
         Velocity(-3100.0, 0.0),
         Angle(-Angle::PI / 2.0),
         0.0);

      const double earthGravitationalParameter = 3.986004418e14;
      const double initialRadius = 42164000.0;
      const double gravity =
         earthGravitationalParameter /
         (initialRadius * initialRadius);

      satellite.update(1.0);

      const double expectedX = -3100.0;
      const double expectedY = initialRadius - 0.5 * gravity;
      const double expectedDY = -gravity;

      assertEqualsTolerance(
         satellite.position.getMetersX(),
         expectedX,
         0.0001);

      assertEqualsTolerance(
         satellite.position.getMetersY(),
         expectedY,
         0.0001);

      assertEqualsTolerance(
         satellite.velocity.getDX(),
         -3100.0,
         0.0001);

      assertEqualsTolerance(
         satellite.velocity.getDY(),
         expectedDY,
         0.0001);
      assertEquals(
         satellite.orientation.getRadians(),
         -Angle::PI / 2.0);
   }

   void makeDefunct()
   {
      Satellite satellite(
         SatelliteType::GPS,
         Position(0.0, 42164000.0),
         Velocity(-3100.0, 0.0),
         Angle(-Angle::PI / 2.0),
         0.0);

      satellite.makeDefunct();

      assertUnit(satellite.defunct);
      assertUnit(satellite.isDefunct());
   }

   void testBreakApart()
   {
      Satellite satellite(
         SatelliteType::GPS,
         Position(0.0, 42164000.0),
         Velocity(-3100.0, 0.0),
         Angle(-Angle::PI / 2.0),
         0.0);

      std::vector<SpaceObject*> parts = satellite.breakApart();

      assertUnit(parts.empty());
   }
};