/***********************************************************************
 * Source File:
 *    Test Acceleration : Test the Acceleration class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Acceleration
 ************************************************************************/

#include "testAcceleration.h"

void TestAcceleration::run()
{
   construct_default();
   construct_nonDefault();
   getDDX();
   getDDY();
   getMagnitude();
   getMagnitude_zero();
   getMagnitude_negative();
   setDDX();
   setDDY();
   add();
   add_cancelling();

   report("Acceleration");
}

void TestAcceleration::construct_default()
{
   Acceleration acceleration;
   assertEquals(acceleration.ddx, 0.0);
   assertEquals(acceleration.ddy, 0.0);
}

void TestAcceleration::construct_nonDefault()
{
   Acceleration acceleration(3.0, 4.0);
   assertEquals(acceleration.ddx, 3.0);
   assertEquals(acceleration.ddy, 4.0);
}

void TestAcceleration::getDDX()
{
   Acceleration acceleration(3.0, 4.0);
   assertEquals(acceleration.getDDX(), 3.0);
}

void TestAcceleration::getDDY()
{
   Acceleration acceleration(3.0, 4.0);
   assertEquals(acceleration.getDDY(), 4.0);
}

void TestAcceleration::getMagnitude()
{
   Acceleration acceleration(3.0, 4.0);
   assertEquals(acceleration.getMagnitude(), 5.0);
}

void TestAcceleration::getMagnitude_zero()
{
   Acceleration acceleration(0.0, 0.0);
   assertEquals(acceleration.getMagnitude(), 0.0);
}

void TestAcceleration::getMagnitude_negative()
{
   Acceleration acceleration(-6.0, -8.0);
   assertEquals(acceleration.getMagnitude(), 10.0);
}

void TestAcceleration::setDDX()
{
   Acceleration acceleration(3.0, 4.0);
   acceleration.setDDX(-2.0);
   assertEquals(acceleration.ddx, -2.0);
   assertEquals(acceleration.ddy, 4.0);
}

void TestAcceleration::setDDY()
{
   Acceleration acceleration(3.0, 4.0);
   acceleration.setDDY(-2.0);
   assertEquals(acceleration.ddx, 3.0);
   assertEquals(acceleration.ddy, -2.0);
}

void TestAcceleration::add()
{
   Acceleration acceleration(3.0, 4.0);
   Acceleration rhs(2.0, -1.0);
   acceleration.add(rhs);
   assertEquals(acceleration.ddx, 5.0);
   assertEquals(acceleration.ddy, 3.0);
}

void TestAcceleration::add_cancelling()
{
   Acceleration acceleration(7.5, -4.2);
   Acceleration opposite(-7.5, 4.2);
   acceleration.add(opposite);
   assertEqualsTolerance(acceleration.ddx, 0.0, 0.00001);
   assertEqualsTolerance(acceleration.ddy, 0.0, 0.00001);
}