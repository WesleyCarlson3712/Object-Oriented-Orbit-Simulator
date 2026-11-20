/***********************************************************************
 * Source File:
 *    Test Angle : Test the Angle class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Angle
 ************************************************************************/

#include "testAngle.h"

void TestAngle::run()
{
   // Constructors
   construct_default();
   construct_nonDefault();

   // Getters
   getRadians();
   getDegrees();
   getDx();
   getDy();

   // Setters
   setRadians();
   setDegrees();
   setDxDy();
   add();

   report("Angle");
}

void TestAngle::construct_default()
{
   Angle angle;
   assertEquals(angle.radians, 0.0);
}

void TestAngle::construct_nonDefault()
{
   Angle angle(Angle::PI / 2.0);
   assertEquals(angle.radians, Angle::PI / 2.0);
}

void TestAngle::getRadians()
{
   Angle angle;
   angle.radians = Angle::PI / 4.0;
   assertEquals(angle.getRadians(), Angle::PI / 4.0);
}

void TestAngle::getDegrees()
{
   Angle angle(Angle::PI / 2.0);
   assertEquals(angle.getDegrees(), 90.0);
}

void TestAngle::getDx()
{
   Angle angle(Angle::PI / 3.0);
   assertEquals(angle.getDx(), 0.5);
}

void TestAngle::getDy()
{
   Angle angle(Angle::PI / 6.0);
   assertEquals(angle.getDy(), 0.5);
}

void TestAngle::setRadians()
{
   Angle angle;
   angle.setRadians(Angle::PI);
   assertEquals(angle.radians, Angle::PI);
   assertEquals(angle.getDegrees(), 180.0);
}

void TestAngle::setDegrees()
{
   Angle angle;
   angle.setDegrees(270.0);
   assertEquals(angle.radians, Angle::PI * 1.5);
   assertEquals(angle.getDegrees(), 270.0);
}

void TestAngle::setDxDy()
{
   Angle angle;
   angle.setDxDy(0.0, -1.0);
   assertEquals(angle.getRadians(), -Angle::PI / 2.0);
}

void TestAngle::add()
{
   Angle angle(Angle::PI / 4.0);
   Angle& result = angle.add(Angle::PI / 4.0);

   assertUnit(&result == &angle);
   assertEquals(angle.getRadians(), Angle::PI / 2.0);
}