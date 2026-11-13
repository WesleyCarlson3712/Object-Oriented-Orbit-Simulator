#pragma once

#include "earth.h"
#include "unitTest.h"

class TestEarth : public UnitTest
{
public:
   void run()
   {
      construct_default();
      update();

      report("Earth");
   }

private:
   void construct_default()
   {
      Earth earth;

      assertEquals(earth.position.getMetersX(), 0.0);
      assertEquals(earth.position.getMetersY(), 0.0);
      assertEquals(earth.orientation.getRadians(), 0.0);
      assertEquals(
         earth.rotationRate,
         -2.0 * Angle::PI / (24.0 * 60.0 * 60.0));
   }

   void update()
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
};