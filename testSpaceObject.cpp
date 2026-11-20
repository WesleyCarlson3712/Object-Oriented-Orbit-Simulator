/***********************************************************************
 * Source File:
 *    Test SpaceObject : Test the SpaceObject class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for SpaceObject, acting as a test double.
 ************************************************************************/

#include "testSpaceObject.h"
#include <cmath>

void TestSpaceObject::update(double time)
{
   Acceleration acceleration = computeGravity();
   updatePosition(acceleration, time);
   updateVelocity(acceleration, time);
   updateRotation(time);
}

void TestSpaceObject::draw(ogstream&)
{
}

std::vector<SpaceObject*> TestSpaceObject::breakApart()
{
   return {};
}

void TestSpaceObject::run()
{
   construct_default();
   testDestroy();
   testRotate();
   testUpdateRotation();
   testCollidesWith();

   // Physics: Inertia
   testInertia_constantVelocity();
   testInertia_atRest();

   // Physics: Position
   testUpdatePosition_combined();
   testUpdatePosition_zeroVelocity();
   testUpdatePosition_zeroAcceleration();
   testUpdatePosition_negative();

   // Physics: Velocity
   testUpdateVelocity_combined();
   testUpdateVelocity_zeroAcceleration();
   testUpdateVelocity_deceleration();
   testUpdateVelocity_negative();

   // Physics: Gravity
   testComputeGravity_nearSurface();
   testComputeGravity_geostationaryY();
   testComputeGravity_geostationaryX();
   testComputeGravity_negativeQuadrant();
   testComputeGravity_diagonal();

   // Physics: Full Simulation Step
   testUpdate_fullStep();

   report("SpaceObject");
}

void TestSpaceObject::construct_default()
{
   TestSpaceObject object;

   assertEquals(object.position.getMetersX(), 0.0);
   assertEquals(object.position.getMetersY(), 0.0);
   assertEquals(object.velocity.getDX(), 0.0);
   assertEquals(object.velocity.getDY(), 0.0);
   assertEquals(object.radius, 0.0);
   assertUnit(object.alive);
   assertEquals(object.orientation.getRadians(), 0.0);
   assertEquals(object.rotationRate, 0.0);
}

void TestSpaceObject::testDestroy()
{
   TestSpaceObject object;
   object.destroy();

   assertUnit(!object.isAlive());
}

void TestSpaceObject::testRotate()
{
   TestSpaceObject object;
   object.rotate(0.75);

   assertEquals(object.getOrientation().getRadians(), 0.75);
}

void TestSpaceObject::testUpdateRotation()
{
   TestSpaceObject object;
   object.rotationRate = 0.5;
   object.updateRotation(4.0);

   assertEquals(object.getOrientation().getRadians(), 2.0);
}

void TestSpaceObject::testCollidesWith()
{
   TestSpaceObject first;
   TestSpaceObject second;
   first.position.setMeters(0.0, 0.0);
   second.position.setMeters(7.0, 0.0);
   first.radius = 5.0;
   second.radius = 3.0;

   assertUnit(first.collidesWith(second));

   second.position.setMeters(9.0, 0.0);
   assertUnit(!first.collidesWith(second));
}

/*********************************************************
 * INERTIA : CONSTANT VELOCITY
 * Newton's 1st Law: An object in motion continues in motion
 * with constant velocity when acceleration is zero.
 *********************************************************/
void TestSpaceObject::testInertia_constantVelocity()
{
   TestSpaceObject object;
   object.position.setMeters(100.0, 200.0);
   object.velocity = Velocity(15.0, -25.0);
   Acceleration zeroAccel(0.0, 0.0);

   object.updatePosition(zeroAccel, 4.0);
   object.updateVelocity(zeroAccel, 4.0);

   assertEquals(object.position.getMetersX(), 160.0);
   assertEquals(object.position.getMetersY(), 100.0);
   assertEquals(object.velocity.getDX(), 15.0);
   assertEquals(object.velocity.getDY(), -25.0);
}

/*********************************************************
 * INERTIA : AT REST
 * Newton's 1st Law: An object at rest remains at rest
 * when acceleration is zero.
 *********************************************************/
void TestSpaceObject::testInertia_atRest()
{
   TestSpaceObject object;
   object.position.setMeters(50.0, -50.0);
   object.velocity = Velocity(0.0, 0.0);
   Acceleration zeroAccel(0.0, 0.0);

   object.updatePosition(zeroAccel, 10.0);
   object.updateVelocity(zeroAccel, 10.0);

   assertEquals(object.position.getMetersX(), 50.0);
   assertEquals(object.position.getMetersY(), -50.0);
   assertEquals(object.velocity.getDX(), 0.0);
   assertEquals(object.velocity.getDY(), 0.0);
}

/*********************************************************
 * POSITION : COMBINED
 * x = x0 + v*t + 0.5*a*t^2
 *********************************************************/
void TestSpaceObject::testUpdatePosition_combined()
{
   TestSpaceObject object;
   object.velocity = Velocity(10.0, 20.0);
   Acceleration acceleration(2.0, 4.0);

   object.updatePosition(acceleration, 3.0);

   assertEquals(object.position.getMetersX(), 39.0);
   assertEquals(object.position.getMetersY(), 78.0);
}

/*********************************************************
 * POSITION : ZERO INITIAL VELOCITY
 * Position changes solely from acceleration.
 *********************************************************/
void TestSpaceObject::testUpdatePosition_zeroVelocity()
{
   TestSpaceObject object;
   object.position.setMeters(0.0, 0.0);
   object.velocity = Velocity(0.0, 0.0);
   Acceleration acceleration(4.0, -6.0);

   object.updatePosition(acceleration, 3.0);

   assertEquals(object.position.getMetersX(), 18.0);
   assertEquals(object.position.getMetersY(), -27.0);
}

/*********************************************************
 * POSITION : ZERO ACCELERATION
 * Position changes solely from velocity (linear motion).
 *********************************************************/
void TestSpaceObject::testUpdatePosition_zeroAcceleration()
{
   TestSpaceObject object;
   object.position.setMeters(5.0, 10.0);
   object.velocity = Velocity(10.0, 20.0);
   Acceleration acceleration(0.0, 0.0);

   object.updatePosition(acceleration, 3.0);

   assertEquals(object.position.getMetersX(), 35.0);
   assertEquals(object.position.getMetersY(), 70.0);
}

/*********************************************************
 * POSITION : NEGATIVE COMPONENTS
 * Handles negative initial velocity and negative acceleration.
 *********************************************************/
void TestSpaceObject::testUpdatePosition_negative()
{
   TestSpaceObject object;
   object.position.setMeters(0.0, 0.0);
   object.velocity = Velocity(-10.0, -20.0);
   Acceleration acceleration(-2.0, -4.0);

   object.updatePosition(acceleration, 2.0);

   assertEquals(object.position.getMetersX(), -24.0);
   assertEquals(object.position.getMetersY(), -48.0);
}

/*********************************************************
 * VELOCITY : COMBINED
 * v = v0 + a*t
 *********************************************************/
void TestSpaceObject::testUpdateVelocity_combined()
{
   TestSpaceObject object;
   object.velocity = Velocity(10.0, 20.0);
   Acceleration acceleration(2.0, -4.0);

   object.updateVelocity(acceleration, 3.0);

   assertEquals(object.velocity.getDX(), 16.0);
   assertEquals(object.velocity.getDY(), 8.0);
}

/*********************************************************
 * VELOCITY : ZERO ACCELERATION
 * Velocity remains unchanged.
 *********************************************************/
void TestSpaceObject::testUpdateVelocity_zeroAcceleration()
{
   TestSpaceObject object;
   object.velocity = Velocity(15.0, -30.0);
   Acceleration zeroAccel(0.0, 0.0);

   object.updateVelocity(zeroAccel, 5.0);

   assertEquals(object.velocity.getDX(), 15.0);
   assertEquals(object.velocity.getDY(), -30.0);
}

/*********************************************************
 * VELOCITY : DECELERATION TO ZERO
 * Deceleration bringing velocity exactly to rest.
 *********************************************************/
void TestSpaceObject::testUpdateVelocity_deceleration()
{
   TestSpaceObject object;
   object.velocity = Velocity(20.0, 40.0);
   Acceleration acceleration(-5.0, -10.0);

   object.updateVelocity(acceleration, 4.0);

   assertEquals(object.velocity.getDX(), 0.0);
   assertEquals(object.velocity.getDY(), 0.0);
}

/*********************************************************
 * VELOCITY : NEGATIVE INITIAL AND NEGATIVE ACCELERATION
 *********************************************************/
void TestSpaceObject::testUpdateVelocity_negative()
{
   TestSpaceObject object;
   object.velocity = Velocity(-10.0, 5.0);
   Acceleration acceleration(-3.0, 2.0);

   object.updateVelocity(acceleration, 2.0);

   assertEquals(object.velocity.getDX(), -16.0);
   assertEquals(object.velocity.getDY(), 9.0);
}

/*********************************************************
 * GRAVITY : NEAR EARTH SURFACE
 * Radius = 6,378,000 m -> g ~ 9.798 m/s^2 directed down
 *********************************************************/
void TestSpaceObject::testComputeGravity_nearSurface()
{
   TestSpaceObject object;
   object.position.setMeters(0.0, 6378000.0);

   Acceleration acceleration = object.computeGravity();

   assertEqualsTolerance(acceleration.getDDX(), 0.0, 0.0001);
   assertEqualsTolerance(acceleration.getDDY(), -9.7987, 0.01);
}

/*********************************************************
 * GRAVITY : GEOSTATIONARY ORBIT (POSITIVE Y)
 * Radius = 42,164,000 m -> g ~ 0.2242 m/s^2 directed down
 *********************************************************/
void TestSpaceObject::testComputeGravity_geostationaryY()
{
   TestSpaceObject object;
   object.position.setMeters(0.0, 42164000.0);

   Acceleration acceleration = object.computeGravity();

   assertEqualsTolerance(acceleration.getDDX(), 0.0, 0.00001);
   assertEqualsTolerance(acceleration.getDDY(), -0.22421, 0.0001);
}

/*********************************************************
 * GRAVITY : GEOSTATIONARY ORBIT (POSITIVE X)
 * Radius = 42,164,000 m -> g ~ 0.2242 m/s^2 directed left
 *********************************************************/
void TestSpaceObject::testComputeGravity_geostationaryX()
{
   TestSpaceObject object;
   object.position.setMeters(42164000.0, 0.0);

   Acceleration acceleration = object.computeGravity();

   assertEqualsTolerance(acceleration.getDDX(), -0.22421, 0.0001);
   assertEqualsTolerance(acceleration.getDDY(), 0.0, 0.00001);
}

/*********************************************************
 * GRAVITY : NEGATIVE QUADRANTS
 * Gravity points inward toward Earth center (0, 0)
 *********************************************************/
void TestSpaceObject::testComputeGravity_negativeQuadrant()
{
   TestSpaceObject objectX;
   objectX.position.setMeters(-42164000.0, 0.0);
   Acceleration accelX = objectX.computeGravity();
   assertEqualsTolerance(accelX.getDDX(), 0.22421, 0.0001);
   assertEqualsTolerance(accelX.getDDY(), 0.0, 0.00001);

   TestSpaceObject objectY;
   objectY.position.setMeters(0.0, -42164000.0);
   Acceleration accelY = objectY.computeGravity();
   assertEqualsTolerance(accelY.getDDX(), 0.0, 0.00001);
   assertEqualsTolerance(accelY.getDDY(), 0.22421, 0.0001);
}

/*********************************************************
 * GRAVITY : DIAGONAL (3-4-5 RIGHT TRIANGLE)
 * Position = (30,000,000, 40,000,000) -> distance = 50,000,000 m
 * Total g = 0.15944 m/s^2, ddx = -0.09566, ddy = -0.12755
 *********************************************************/
void TestSpaceObject::testComputeGravity_diagonal()
{
   TestSpaceObject object;
   object.position.setMeters(30000000.0, 40000000.0);

   Acceleration acceleration = object.computeGravity();

   assertEqualsTolerance(acceleration.getDDX(), -0.09566, 0.0001);
   assertEqualsTolerance(acceleration.getDDY(), -0.12755, 0.0001);
}

/*********************************************************
 * FULL SIMULATION STEP
 * Verify position, velocity, and rotation update harmoniously
 * through one full step of physics.
 *********************************************************/
void TestSpaceObject::testUpdate_fullStep()
{
   TestSpaceObject object;
   object.position.setMeters(0.0, 42164000.0);
   object.velocity = Velocity(-3100.0, 0.0);
   object.rotationRate = 0.05;

   object.update(1.0);

   const double expectedX = -3100.0;
   const double expectedY = 42164000.0 - 0.5 * 0.22420958;
   const double expectedDY = -0.22420958;

   assertEqualsTolerance(object.position.getMetersX(), expectedX, 0.001);
   assertEqualsTolerance(object.position.getMetersY(), expectedY, 0.001);
   assertEqualsTolerance(object.velocity.getDX(), -3100.0, 0.001);
   assertEqualsTolerance(object.velocity.getDY(), expectedDY, 0.001);
   assertEqualsTolerance(object.getOrientation().getRadians(), 0.05, 0.00001);
}