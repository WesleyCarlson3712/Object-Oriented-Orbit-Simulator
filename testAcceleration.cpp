/***********************************************************************
 * Source File:
 *    Test Acceleration : Test the Acceleration class
 * Author:
 *    Jon, Copilot / Antigravity
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
   setDDX();
   setDDY();
   add();

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