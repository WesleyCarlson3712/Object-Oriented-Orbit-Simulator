/***********************************************************************
 * Source File:
 *    Test Ship : Test the Ship class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Ship
 ************************************************************************/

#include "testShip.h"
#include "uiDraw.h"
#include <cmath>

 /*****************************************************************
  * RUN
  * Run all the unit tests for Ship
  *****************************************************************/
void TestShip::run()
{
   construct_default();
   construct_nonDefault();
   setThrust();
   turn();
   thrust_method();
   update_coasting();
   update_thrusting();
   update_rotation();
   breakApart();
   draw_thrustOff();
   draw_thrustOn();

   report("Ship");
}

void TestShip::construct_default()
{
   Ship ship;

   assertEquals(ship.radius, 10.0);
   assertEquals(ship.position.getMetersX(), 0.0);
   assertEquals(ship.position.getMetersY(), 42164000.0);
   assertEquals(ship.velocity.getDX(), -2100.0);
   assertEquals(ship.velocity.getDY(), 0.0);
   assertEquals(ship.orientation.getRadians(), 0.0);
   assertUnit(!ship.isThrusting());
   assertUnit(!ship.engine.isActive());
}

void TestShip::construct_nonDefault()
{
   Position pos(100.0, 200.0);
   Velocity vel(300.0, 400.0);
   Angle angle(1.5);
   double rate = 0.05;

   Ship ship(pos, vel, angle, rate);

   assertEquals(ship.radius, 10.0);
   assertEquals(ship.position.getMetersX(), 100.0);
   assertEquals(ship.position.getMetersY(), 200.0);
   assertEquals(ship.velocity.getDX(), 300.0);
   assertEquals(ship.velocity.getDY(), 400.0);
   assertEquals(ship.orientation.getRadians(), 1.5);
   assertEquals(ship.rotationRate, 0.05);
   assertUnit(!ship.isThrusting());
}

void TestShip::setThrust()
{
   Ship ship;

   ship.setThrust(true);
   assertUnit(ship.isThrusting());
   assertUnit(ship.engine.isActive());

   ship.setThrust(false);
   assertUnit(!ship.isThrusting());
   assertUnit(!ship.engine.isActive());
}

void TestShip::turn()
{
   Ship ship;
   ship.orientation.setRadians(0.0);

   ship.turn(0.1);
   assertEqualsTolerance(ship.orientation.getRadians(), 0.1, 0.0001);

   ship.turn(-0.3);
   assertEqualsTolerance(ship.orientation.getRadians(), -0.2, 0.0001);
}

void TestShip::thrust_method()
{
   Ship ship;
   ship.orientation.setRadians(0.0); // Facing straight up (+Y)
   ship.velocity = Velocity(0.0, 0.0);
   ship.setThrust(true);

   ship.thrust(2.0); // 2.0 m/s^2 * 2.0 s = 4.0 m/s in +Y

   assertEqualsTolerance(ship.velocity.getDX(), 0.0, 0.0001);
   assertEqualsTolerance(ship.velocity.getDY(), 4.0, 0.0001);
}

void TestShip::update_coasting()
{
   // Ship coasting (thrust off) under gravity at geostationary orbit
   Ship ship;
   ship.position.setMeters(0.0, 42164000.0);
   ship.velocity = Velocity(0.0, 0.0);
   ship.orientation.setRadians(0.0);
   ship.setThrust(false);

   const double initialRadius = 42164000.0;
   const double gravity = 3.986004418e14 / (initialRadius * initialRadius);

   double time = 2.0;
   ship.update(time);

   double expectedY = initialRadius - 0.5 * gravity * (time * time);
   double expectedDY = -gravity * time;

   assertEqualsTolerance(ship.position.getMetersX(), 0.0, 0.0001);
   assertEqualsTolerance(ship.position.getMetersY(), expectedY, 0.01);
   assertEqualsTolerance(ship.velocity.getDX(), 0.0, 0.0001);
   assertEqualsTolerance(ship.velocity.getDY(), expectedDY, 0.001);
}

void TestShip::update_thrusting()
{
   // Ship thrusting upward against gravity
   Ship ship;
   ship.position.setMeters(0.0, 42164000.0);
   ship.velocity = Velocity(0.0, 0.0);
   ship.orientation.setRadians(0.0); // facing +Y
   ship.setThrust(true);

   const double initialRadius = 42164000.0;
   const double gravity = 3.986004418e14 / (initialRadius * initialRadius);

   // Thrust is 2.0 upward (+Y), gravity is downward (-Y)
   double netDDY = 2.0 - gravity;
   double time = 2.0;

   ship.update(time);

   double expectedY = initialRadius + 0.5 * netDDY * (time * time);
   double expectedDY = netDDY * time;

   assertEqualsTolerance(ship.position.getMetersX(), 0.0, 0.0001);
   assertEqualsTolerance(ship.position.getMetersY(), expectedY, 0.01);
   assertEqualsTolerance(ship.velocity.getDX(), 0.0, 0.0001);
   assertEqualsTolerance(ship.velocity.getDY(), expectedDY, 0.001);
}

void TestShip::update_rotation()
{
   Ship ship;
   ship.position.setMeters(0.0, 42164000.0);
   ship.velocity = Velocity(0.0, 0.0);
   ship.orientation.setRadians(0.0);
   ship.rotationRate = 0.05;
   ship.setThrust(false);

   ship.update(2.0);

   assertEqualsTolerance(ship.orientation.getRadians(), 0.10, 0.0001);
}

void TestShip::breakApart()
{
   Ship ship;

   std::vector<SpaceObject*> parts = ship.breakApart();

   assertUnit(parts.empty());
}

void TestShip::draw_thrustOff()
{
   Ship ship;
   Position pt;
   ogstreamFake fake(pt);

   ship.setThrust(false);
   ship.draw(fake);

   fake.str("");
   assertUnit(true);
}

void TestShip::draw_thrustOn()
{
   Ship ship;
   Position pt;
   ogstreamFake fake(pt);

   ship.setThrust(true);
   ship.draw(fake);

   fake.str("");
   assertUnit(true);
}