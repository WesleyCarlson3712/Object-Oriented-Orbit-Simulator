#include "spaceObject.h"

#include "physics.h"

SpaceObject::SpaceObject() :
   position(),
   velocity(),
   radius(0.0),
   alive(true),
   orientation(),
   rotationRate(0.0)
{
}

bool SpaceObject::collidesWith(SpaceObject& other) const
{
   return computeDistance(position, other.position) <= radius + other.radius;
}

void SpaceObject::rotate(double delta)
{
   orientation.add(delta);
}

void SpaceObject::updatePosition(const Acceleration& acceleration, double time)
{
   ::updatePosition(position, velocity, acceleration, time);
}

void SpaceObject::updateVelocity(const Acceleration& acceleration, double time)
{
   ::updateVelocity(velocity, acceleration, time);
}

void SpaceObject::updateRotation(double time)
{
   orientation.add(rotationRate * time);
}

Acceleration SpaceObject::computeGravity() const
{
   return ::computeGravity(position);
}
