/***********************************************************************
 * Source File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Jon, Copilot / Antigravity
 * Summary:
 *    All the unit tests for Velocity
 ************************************************************************/

#include "testVelocity.h"
#include <cmath>

void TestVelocity::run()
{
   construct_default();
   construct_nonDefault();
   getDX();
   getDY();
   getSpeed();
   getAngle();
   setDX();
   setDY();
   addDX();
   addDY();
   add();
   addAcceleration();

   report("Velocity");
}

void TestVelocity::construct_default()
{
   Velocity velocity;
   assertEquals(velocity.dx, 0.0);
   assertEquals(velocity.dy, 0.0);
}

void TestVelocity::construct_nonDefault()
{
   Velocity velocity(-3100.0, 0.0);
   assertEquals(velocity.dx, -3100.0);
   assertEquals(velocity.dy, 0.0);
}

void TestVelocity::getDX()
{
   Velocity velocity;
   velocity.dx = 12.5;
   velocity.dy = -8.0;
   assertEquals(velocity.getDX(), 12.5);
   assertEquals(velocity.dy, -8.0);
}

void TestVelocity::getDY()
{
   Velocity velocity;
   velocity.dx = 12.5;
   velocity.dy = -8.0;
   assertEquals(velocity.dx, 12.5);
   assertEquals(velocity.getDY(), -8.0);
}

void TestVelocity::getSpeed()
{
   Velocity velocity(3.0, 4.0);
   assertEquals(velocity.getSpeed(), 5.0);
}

void TestVelocity::getAngle()
{
   Velocity velocity(3.0, 4.0);
   assertEquals(velocity.getAngle().getRadians(), std::atan2(4.0, 3.0));
}

void TestVelocity::setDX()
{
   Velocity velocity(10.0, 20.0);
   velocity.setDX(-3.5);
   assertEquals(velocity.dx, -3.5);
   assertEquals(velocity.dy, 20.0);
}

void TestVelocity::setDY()
{
   Velocity velocity(10.0, 20.0);
   velocity.setDY(-3.5);
   assertEquals(velocity.dx, 10.0);
   assertEquals(velocity.dy, -3.5);
}

void TestVelocity::addDX()
{
   Velocity velocity(10.0, 20.0);
   velocity.addDX(-3.5);
   assertEquals(velocity.dx, 6.5);
   assertEquals(velocity.dy, 20.0);
}

void TestVelocity::addDY()
{
   Velocity velocity(10.0, 20.0);
   velocity.addDY(-3.5);
   assertEquals(velocity.dx, 10.0);
   assertEquals(velocity.dy, 16.5);
}

void TestVelocity::add()
{
   Velocity velocity(10.0, 20.0);
   Acceleration acceleration(2.0, -4.0);
   velocity.add(acceleration, 3.0);
   assertEquals(velocity.dx, 16.0);
   assertEquals(velocity.dy, 8.0);
}

void TestVelocity::addAcceleration()
{
   Velocity velocity(10.0, 20.0);
   Acceleration acceleration(2.0, -4.0);
   velocity.add(acceleration, 3.0);
   assertEquals(velocity.dx, 16.0);
   assertEquals(velocity.dy, 8.0);
}