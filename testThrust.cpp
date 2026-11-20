/***********************************************************************
 * Source File:
 *    Test Thrust : Test the Thrust class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Thrust
 ************************************************************************/

#include "testThrust.h"
#include <cmath>

 /*****************************************************************
  * RUN
  * Run all the unit tests for Thrust
  *****************************************************************/
void TestThrust::run()
{
   construct_default();
   activate();
   deactivate();
   setMagnitude();
   getAcceleration_inactive();
   getAcceleration_activeFacingUp();
   getAcceleration_activeFacingRight();
   getAcceleration_activeFacingDown();
   getAcceleration_activeFacingLeft();
   getAcceleration_activeDiagonal();

   report("Thrust");
}

void TestThrust::construct_default()
{
   Thrust thrust;

   assertUnit(!thrust.active);
   assertUnit(!thrust.isActive());
   assertEquals(thrust.magnitude, 2.0);
   assertEquals(thrust.getMagnitude(), 2.0);
}

void TestThrust::activate()
{
   Thrust thrust;
   thrust.active = false;

   thrust.activate();

   assertUnit(thrust.active);
   assertUnit(thrust.isActive());
}

void TestThrust::deactivate()
{
   Thrust thrust;
   thrust.active = true;

   thrust.deactivate();

   assertUnit(!thrust.active);
   assertUnit(!thrust.isActive());
}

void TestThrust::setMagnitude()
{
   Thrust thrust;

   thrust.setMagnitude(5.5);

   assertEquals(thrust.magnitude, 5.5);
   assertEquals(thrust.getMagnitude(), 5.5);
}

void TestThrust::getAcceleration_inactive()
{
   Thrust thrust;
   thrust.active = false;
   thrust.magnitude = 2.0;

   Angle direction(Angle::PI / 4.0);
   Acceleration a = thrust.getAcceleration(direction);

   assertEquals(a.getDDX(), 0.0);
   assertEquals(a.getDDY(), 0.0);
}

void TestThrust::getAcceleration_activeFacingUp()
{
   // Ship facing 0.0 radians (straight up along +Y)
   Thrust thrust;
   thrust.active = true;
   thrust.magnitude = 2.0;

   Angle direction(0.0);
   Acceleration a = thrust.getAcceleration(direction);

   assertEqualsTolerance(a.getDDX(), 0.0, 0.0001);
   assertEqualsTolerance(a.getDDY(), 2.0, 0.0001);
}

void TestThrust::getAcceleration_activeFacingRight()
{
   // Ship facing PI/2 radians (facing right along +X)
   Thrust thrust;
   thrust.active = true;
   thrust.magnitude = 2.0;

   Angle direction(Angle::PI / 2.0);
   Acceleration a = thrust.getAcceleration(direction);

   assertEqualsTolerance(a.getDDX(), 2.0, 0.0001);
   assertEqualsTolerance(a.getDDY(), 0.0, 0.0001);
}

void TestThrust::getAcceleration_activeFacingDown()
{
   // Ship facing PI radians (facing down along -Y)
   Thrust thrust;
   thrust.active = true;
   thrust.magnitude = 2.0;

   Angle direction(Angle::PI);
   Acceleration a = thrust.getAcceleration(direction);

   assertEqualsTolerance(a.getDDX(), 0.0, 0.0001);
   assertEqualsTolerance(a.getDDY(), -2.0, 0.0001);
}

void TestThrust::getAcceleration_activeFacingLeft()
{
   // Ship facing -PI/2 radians (facing left along -X)
   Thrust thrust;
   thrust.active = true;
   thrust.magnitude = 2.0;

   Angle direction(-Angle::PI / 2.0);
   Acceleration a = thrust.getAcceleration(direction);

   assertEqualsTolerance(a.getDDX(), -2.0, 0.0001);
   assertEqualsTolerance(a.getDDY(), 0.0, 0.0001);
}

void TestThrust::getAcceleration_activeDiagonal()
{
   // Ship facing PI/4 radians (45 degrees, diagonal)
   Thrust thrust;
   thrust.active = true;
   thrust.magnitude = 2.0;

   Angle direction(Angle::PI / 4.0);
   Acceleration a = thrust.getAcceleration(direction);

   double expected = 2.0 * std::sin(Angle::PI / 4.0); // ~1.4142 m/s^2
   assertEqualsTolerance(a.getDDX(), expected, 0.0001);
   assertEqualsTolerance(a.getDDY(), expected, 0.0001);
}