/***********************************************************************
 * Source File:
 *    Test Satellite : Test the Satellite class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Satellite
 ************************************************************************/

#include "testSatellite.h"
#include "uiDraw.h"
#include <cmath>

TestSatellite::TestSatellite() :
   Satellite(SatelliteType::GPS,
             Position(0.0, 42164000.0),
             Velocity(-3100.0, 0.0),
             Angle(-Angle::PI / 2.0),
             0.0)
{
}

void TestSatellite::run()
{
   construct_default();
   update();
   update_stationaryFall();
   makeDefunct();
   testBreakApart();
   testDraw();

   report("Satellite");
}

void TestSatellite::construct_default()
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

void TestSatellite::update()
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

/*********************************************************
 * UPDATE : STATIONARY FALL
 * Satellite with 0 velocity falls directly downward along Y axis.
 *********************************************************/
void TestSatellite::update_stationaryFall()
{
   Satellite satellite(
      SatelliteType::GPS,
      Position(0.0, 42164000.0),
      Velocity(0.0, 0.0),
      Angle(0.0),
      0.0);

   const double earthGravitationalParameter = 3.986004418e14;
   const double initialRadius = 42164000.0;
   const double gravity =
      earthGravitationalParameter /
      (initialRadius * initialRadius);

   satellite.update(2.0);

   const double expectedY = initialRadius - 0.5 * gravity * 4.0;
   const double expectedDY = -gravity * 2.0;

   assertEqualsTolerance(satellite.position.getMetersX(), 0.0, 0.0001);
   assertEqualsTolerance(satellite.position.getMetersY(), expectedY, 0.001);
   assertEqualsTolerance(satellite.velocity.getDX(), 0.0, 0.0001);
   assertEqualsTolerance(satellite.velocity.getDY(), expectedDY, 0.001);
}

void TestSatellite::makeDefunct()
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

void TestSatellite::testBreakApart()
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

/*********************************************************
 * TEST DRAW
 * Use test double ogstreamFake to verify polymorphic draw.
 *********************************************************/
void TestSatellite::testDraw()
{
   Satellite satellite(
      SatelliteType::GPS,
      Position(100.0, 200.0),
      Velocity(-3100.0, 0.0),
      Angle(0.5),
      0.0);

   Position pt;
   ogstreamFake fake(pt);
   satellite.draw(fake);
   fake.str("");

   assertUnit(true);
}
