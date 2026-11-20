/***********************************************************************
 * Source File:
 *    Test Earth : Test the Earth class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Earth
 ************************************************************************/

#include "testEarth.h"

void TestEarth::run()
{
   construct_default();
   update();

   report("Earth");
}

void TestEarth::construct_default()
{
   Earth earth;

   assertEquals(earth.position.getMetersX(), 0.0);
   assertEquals(earth.position.getMetersY(), 0.0);
   assertEquals(earth.orientation.getRadians(), 0.0);
   assertEquals(
      earth.rotationRate,
      -2.0 * Angle::PI / (24.0 * 60.0 * 60.0));
}

void TestEarth::update()
{
   Earth earth;

   const double seconds = 48.0;
   const double expected =
      -2.0 * Angle::PI * seconds / (24.0 * 60.0 * 60.0);

   earth.update(seconds);

   assertEqualsTolerance(
      earth.orientation.getRadians(),
      expected,
      0.0000001);
}