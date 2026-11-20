#pragma once

#include "satellite.h"
#include "unitTest.h"

/***********************************************************************
 * Header File:
 *    Test Satellite : Test the Satellite class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Satellite
 ************************************************************************/
class TestSatellite : public Satellite, public UnitTest
{
public:
   TestSatellite();

   void run();

private:
   void construct_default();
   void update();
   void update_stationaryFall();
   void makeDefunct();
   void testBreakApart();
   void testDraw();
};