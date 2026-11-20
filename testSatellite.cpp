/***********************************************************************
 * Source File:
 *    Test Satellite : Test the Satellite class and its subclasses
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Satellite, acting as a test double.
 ************************************************************************/

#include "testSatellite.h"
#include "uiDraw.h"
#include "sputnik.h"
#include "gps.h"
#include "hubble.h"
#include "crewDragon.h"
#include "starlink.h"
#include <cmath>

TestSatellite::TestSatellite() :
   Satellite(Position(0.0, 42164000.0),
             Velocity(-3100.0, 0.0),
             Angle(-Angle::PI / 2.0),
             0.0)
{
}

TestSatellite::TestSatellite(const Position& position,
                             const Velocity& velocity,
                             const Angle& orientation,
                             double rotationRate) :
   Satellite(position, velocity, orientation, rotationRate)
{
}

void TestSatellite::draw(ogstream& out)
{
   out.drawGPS(position, orientation.getRadians());
}

std::vector<SpaceObject*> TestSatellite::breakApart()
{
   return {};
}

void TestSatellite::run()
{
   testConstruct_default();
   testUpdate();
   testUpdate_stationaryFall();
   testMakeDefunct();
   testBreakApart();
   testDraw();

   // Polymorphic satellite subtype tests
   testSputnik();
   testGPS();
   testHubble();
   testCrewDragon();
   testStarlink();

   report("Satellite");
}

void TestSatellite::testConstruct_default()
{
   TestSatellite satellite(
      Position(0.0, 42164000.0),
      Velocity(-3100.0, 0.0),
      Angle(-Angle::PI / 2.0),
      0.0);

   assertUnit(!satellite.defunct);
   assertEquals(satellite.position.getMetersX(), 0.0);
   assertEquals(satellite.position.getMetersY(), 42164000.0);
   assertEquals(satellite.velocity.getDX(), -3100.0);
   assertEquals(satellite.velocity.getDY(), 0.0);
   assertEquals(satellite.orientation.getRadians(), -Angle::PI / 2.0);
}

void TestSatellite::testUpdate()
{
   TestSatellite satellite(
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

   assertEqualsTolerance(satellite.position.getMetersX(), expectedX, 0.0001);
   assertEqualsTolerance(satellite.position.getMetersY(), expectedY, 0.0001);
   assertEqualsTolerance(satellite.velocity.getDX(), -3100.0, 0.0001);
   assertEqualsTolerance(satellite.velocity.getDY(), expectedDY, 0.0001);
   assertEquals(satellite.orientation.getRadians(), -Angle::PI / 2.0);
}

void TestSatellite::testUpdate_stationaryFall()
{
   TestSatellite satellite(
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

void TestSatellite::testMakeDefunct()
{
   TestSatellite satellite(
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
   TestSatellite satellite(
      Position(0.0, 42164000.0),
      Velocity(-3100.0, 0.0),
      Angle(-Angle::PI / 2.0),
      0.0);

   std::vector<SpaceObject*> parts = satellite.breakApart();

   assertUnit(parts.empty());
}

void TestSatellite::testDraw()
{
   TestSatellite satellite(
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

/*********************************************************
 * SUBCLASS TEST : SPUTNIK
 *********************************************************/
void TestSatellite::testSputnik()
{
   Sputnik sputnik;
   assertUnit(sputnik.isAlive());
   assertEquals(sputnik.getRadius(), 4.0);

   Position pt;
   ogstreamFake fake(pt);
   sputnik.draw(fake);
   fake.str("");

   assertUnit(sputnik.breakApart().empty());
}

/*********************************************************
 * SUBCLASS TEST : GPS
 *********************************************************/
void TestSatellite::testGPS()
{
   GPS gps;
   assertUnit(gps.isAlive());
   assertEquals(gps.getRadius(), 12.0);
   assertEquals(gps.getPosition().getMetersX(), 0.0);
   assertEquals(gps.getPosition().getMetersY(), 42164000.0);
   assertEquals(gps.getVelocity().getDX(), -3100.0);
   assertEquals(gps.getVelocity().getDY(), 0.0);

   Position pt;
   ogstreamFake fake(pt);
   gps.draw(fake);
   fake.str("");

   assertUnit(gps.breakApart().empty());
}

/*********************************************************
 * SUBCLASS TEST : HUBBLE
 *********************************************************/
void TestSatellite::testHubble()
{
   Hubble hubble;
   assertUnit(hubble.isAlive());
   assertEquals(hubble.getRadius(), 10.0);

   Position pt;
   ogstreamFake fake(pt);
   hubble.draw(fake);
   fake.str("");

   assertUnit(hubble.breakApart().empty());
}

/*********************************************************
 * SUBCLASS TEST : CREW DRAGON
 *********************************************************/
void TestSatellite::testCrewDragon()
{
   CrewDragon dragon;
   assertUnit(dragon.isAlive());
   assertEquals(dragon.getRadius(), 7.0);

   Position pt;
   ogstreamFake fake(pt);
   dragon.draw(fake);
   fake.str("");

   assertUnit(dragon.breakApart().empty());
}

/*********************************************************
 * SUBCLASS TEST : STARLINK
 *********************************************************/
void TestSatellite::testStarlink()
{
   Starlink starlink;
   assertUnit(starlink.isAlive());
   assertEquals(starlink.getRadius(), 6.0);

   Position pt;
   ogstreamFake fake(pt);
   starlink.draw(fake);
   fake.str("");

   assertUnit(starlink.breakApart().empty());
}
