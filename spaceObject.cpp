#include "spaceObject.h"

#include <cassert>
#include <cmath>

namespace
{
   constexpr double EARTH_GRAVITATIONAL_PARAMETER = 3.986004418e14;
}

/*********************************************
 * SpaceObject : CONSTRUCTOR
 * Initialize the common physical state of a space object.
 *********************************************/
SpaceObject::SpaceObject() :
   position(),
   velocity(),
   radius(0.0),
   alive(true),
   orientation(),
   rotationRate(0.0)
{
}

/*********************************************
 * SpaceObject : COLLIDES WITH
 * Determine whether two objects overlap based on their radii.
 *********************************************/
bool SpaceObject::collidesWith(SpaceObject& other) const
{
   return computeDistance(position, other.position) <= radius + other.radius;
}

/*********************************************
 * SpaceObject : ROTATE
 * Change the object's orientation by delta radians.
 *********************************************/
void SpaceObject::rotate(double delta)
{
   orientation.add(delta);
}

/*********************************************
 * SpaceObject : UPDATE POSITION
 * Update position using velocity and acceleration over time.
 *********************************************/
void SpaceObject::updatePosition(const Acceleration& acceleration, double time)
{
   const double timeSquared = time * time;

   position.addMetersX(velocity.getDX() * time +
                       0.5 * acceleration.getDDX() * timeSquared);
   position.addMetersY(velocity.getDY() * time +
                       0.5 * acceleration.getDDY() * timeSquared);
}

/*********************************************
 * SpaceObject : UPDATE VELOCITY
 * Update velocity using acceleration over time.
 *********************************************/
void SpaceObject::updateVelocity(const Acceleration& acceleration, double time)
{
   velocity.add(acceleration, time);
}

/*********************************************
 * SpaceObject : UPDATE ROTATION
 * Update orientation using rotation rate over time.
 *********************************************/
void SpaceObject::updateRotation(double time)
{
   orientation.add(rotationRate * time);
}

/*********************************************
 * SpaceObject : COMPUTE GRAVITY
 * Compute Earth's gravitational acceleration at the object's position.
 *********************************************/
Acceleration SpaceObject::computeGravity() const
{
   const double x = position.getMetersX();
   const double y = position.getMetersY();
   const double distance = std::sqrt(x * x + y * y);

   assert(distance > 0.0);

   const double gravity = EARTH_GRAVITATIONAL_PARAMETER /
                          (distance * distance);
   return Acceleration(gravity * (-x / distance),
                       gravity * (-y / distance));
}
