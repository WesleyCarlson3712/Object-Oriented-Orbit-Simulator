/***********************************************************************
 * Header File:
 *    Test Satellite : Test the Satellite class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Satellite, acting as a test double.
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "unitTest.h"

/*********************************************
 * TestSatellite
 * Test double inheriting from abstract Satellite.
 *********************************************/
class TestSatellite : public Satellite, public UnitTest
{
public:
   TestSatellite();
   TestSatellite(const Position& position,
                 const Velocity& velocity,
                 const Angle& orientation,
                 double rotationRate);

   void draw(ogstream& out) override;
   std::vector<SpaceObject*> breakApart() override;

   void run();

private:
   void testConstruct_default();
   void testUpdate();
   void testUpdate_stationaryFall();
   void testMakeDefunct();
   void testBreakApart();
   void testDraw();
};
