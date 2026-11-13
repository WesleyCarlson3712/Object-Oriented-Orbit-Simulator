#pragma once

#include "angle.h"
#include "unitTest.h"

/*******************************
 * TEST Angle
 * A friend class for Angle which contains the Angle unit tests
 ********************************/
class TestAngle : public UnitTest
{
public:
   void run()
   {
      // Constructors
      construct_default();
      construct_nonDefault();

      // Getters
      getRadians();
      getDegrees();

      // Setters
      setRadians();
      setDegrees();

      report("Angle");
   }

private:
   void construct_default()
   {
      Angle angle;

      assertEquals(angle.radians, 0.0);
   }

   void construct_nonDefault()
   {
      Angle angle(Angle::PI / 2.0);

      assertEquals(angle.radians, Angle::PI / 2.0);
   }

   void getRadians()
   {
      Angle angle;
      angle.radians = Angle::PI / 4.0;

      assertEquals(angle.getRadians(), Angle::PI / 4.0);
   }

   void getDegrees()
   {
      Angle angle(Angle::PI / 2.0);

      assertEquals(angle.getDegrees(), 90.0);
   }

   void setRadians()
   {
      Angle angle;
      angle.setRadians(Angle::PI);

      assertEquals(angle.radians, Angle::PI);
      assertEquals(angle.getDegrees(), 180.0);
   }

   void setDegrees()
   {
      Angle angle;
      angle.setDegrees(270.0);

      assertEquals(angle.radians, Angle::PI * 1.5);
      assertEquals(angle.getDegrees(), 270.0);
   }
};
