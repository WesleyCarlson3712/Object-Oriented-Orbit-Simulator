#pragma once

#include <vector>

#include "acceleration.h"
#include "angle.h"
#include "position.h"
#include "velocity.h"

class ogstream;

/*********************************************
 * SpaceObject
 * The common base class for physical objects in the simulation.
 *********************************************/
class SpaceObject
{
public:
   /*********************************************
    * DESTRUCTOR
    * Destroy a space object through a base pointer.
    *********************************************/
   virtual ~SpaceObject() = default;

   /*********************************************
    * UPDATE
    * Advance the object through one time step.
    *********************************************/
   virtual void update(double time) = 0;

   /*********************************************
    * DRAW
    * Draw the object.
    *********************************************/
   virtual void draw(ogstream& out) = 0;

   /*********************************************
    * BREAK APART
    * Return the objects created when this object breaks apart.
    *********************************************/
   virtual std::vector<SpaceObject*> breakApart() = 0;

   /*********************************************
    * COLLIDES WITH
    * Determine whether this object overlaps another object.
    *********************************************/
   bool collidesWith(SpaceObject& other) const;

   /*********************************************
    * IS ALIVE
    * Determine whether this object is active.
    *********************************************/
   bool isAlive() const { return alive; }

   /*********************************************
    * DESTROY
    * Mark this object as inactive.
    *********************************************/
   void destroy() { alive = false; }

   /*********************************************
    * ROTATE
    * Change the object's orientation by an angle in radians.
    *********************************************/
   void rotate(double delta);

   /*********************************************
    * GET ORIENTATION
    * Return the object's current orientation.
    *********************************************/
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
