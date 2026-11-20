/***********************************************************************
 * Source File:
 *    Ship : Represents the player-controlled spacecraft
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Implementation of the player-controlled spacecraft.
 ************************************************************************/

#include "ship.h"
#include "uiDraw.h"

 /*********************************************
  * Ship : DEFAULT CONSTRUCTOR
  * Default position at orbit.
  *********************************************/
Ship::Ship() :
   SpaceObject(),
   engine()
{
   position.setMeters(0.0, 42164000.0);
   velocity = Velocity(-2100.0, 0.0);
   orientation.setRadians(0.0);
   radius = 10.0;
}

/*********************************************
 * Ship : NON-DEFAULT CONSTRUCTOR
 *********************************************/
Ship::Ship(const Position& position,
   const Velocity& velocity,
   const Angle& orientation,
   double rotationRate) :
   SpaceObject(),
   engine()
{
   this->position = position;
   this->velocity = velocity;
   this->orientation = orientation;
   this->rotationRate = rotationRate;
   this->radius = 10.0;
}

/*********************************************
 * Ship : SET THRUST
 * Enable or disable main engine thrust.
 *********************************************/
void Ship::setThrust(bool active)
{
   if (active)
      engine.activate();
   else
      engine.deactivate();
}

/*********************************************
 * Ship : IS THRUSTING
 * Query whether the main engine is active.
 *********************************************/
bool Ship::isThrusting() const
{
   return engine.isActive();
}

/*********************************************
 * Ship : TURN
 * Adjust orientation angle by an increment.
 *********************************************/
void Ship::turn(double amount)
{
   orientation.add(amount);
}

/*********************************************
 * Ship : THRUST
 * Apply thrust acceleration to velocity over time.
 *********************************************/
void Ship::thrust(double time)
{
   Acceleration accel = engine.getAcceleration(orientation);
   velocity.add(accel, time);
}

/*********************************************
 * Ship : FIRE
 * Stub for future projectile firing.
 *********************************************/
void Ship::fire()
{
   // Stub for future projectile implementation
}

/*********************************************
 * Ship : UPDATE
 * Advance the ship through one time step under
 * gravity and engine thrust.
 *********************************************/
void Ship::update(double time)
{
   if (!isAlive())
      return;

   Acceleration gravity = computeGravity();
   Acceleration thrustAccel = engine.getAcceleration(orientation);

   Acceleration totalAcceleration(
      gravity.getDDX() + thrustAccel.getDDX(),
      gravity.getDDY() + thrustAccel.getDDY());

   updatePosition(totalAcceleration, time);
   updateVelocity(totalAcceleration, time);
   updateRotation(time);
}

/*********************************************
 * Ship : DRAW
 * Draw the ship on screen, including engine flame if thrusting.
 *********************************************/
void Ship::draw(ogstream& out)
{
   out.drawShip(position, orientation.getRadians(), engine.isActive());
}

/*********************************************
 * Ship : BREAK APART
 * Stub for future collision handling.
 *********************************************/
std::vector<SpaceObject*> Ship::breakApart()
{
   return {};
}