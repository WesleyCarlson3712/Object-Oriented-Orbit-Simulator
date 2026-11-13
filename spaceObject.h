#pragma once

#include <vector>

#include "acceleration.h"
#include "angle.h"
#include "position.h"
#include "velocity.h"

class ogstream;

class SpaceObject
{
public:
   virtual ~SpaceObject() = default;

   virtual void update(double time) = 0;
   virtual void draw(ogstream& out) = 0;
   virtual std::vector<SpaceObject*> breakApart() = 0;

   bool collidesWith(SpaceObject& other) const;
   bool isAlive() const { return alive; }
   void destroy() { alive = false; }

   void rotate(double delta);
   Angle getOrientation() const { return orientation; }

protected:
   SpaceObject();

   void updatePosition(const Acceleration& acceleration, double time);
   void updateVelocity(const Acceleration& acceleration, double time);
   void updateRotation(double time);
   Acceleration computeGravity() const;

   Position position;
   Velocity velocity;
   double radius;
   bool alive;

   Angle orientation;
   double rotationRate;
};
