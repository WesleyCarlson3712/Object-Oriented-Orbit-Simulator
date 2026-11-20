/***********************************************************************
 * Source File:
 *    Satellite : Abstract base class for satellites orbiting the Earth
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Implementation of common satellite physics and behaviors.
 ************************************************************************/

#include "satellite.h"

/*********************************************
 * Satellite : DEFAULT CONSTRUCTOR
 *********************************************/
Satellite::Satellite() :
   SpaceObject(),
   defunct(false),
   uncontrolledRotationRate(0.0)
{
}

/*********************************************
 * Satellite : NON-DEFAULT CONSTRUCTOR
 * Initialize a satellite with its physical state.
 *********************************************/
Satellite::Satellite(const Position& position,
                     const Velocity& velocity,
                     const Angle& orientation,
                     double rotationRate) :
   SpaceObject(),
   defunct(false),
   uncontrolledRotationRate(0.0)
{
   this->position = position;
   this->velocity = velocity;
   this->orientation = orientation;
   this->rotationRate = rotationRate;
}

/*********************************************
 * Satellite : UPDATE
 * Advance the satellite through one time step.
 *********************************************/
void Satellite::update(double time)
{
   if (!isAlive())
      return;

   Acceleration acceleration = computeGravity();

   updatePosition(acceleration, time);
   updateVelocity(acceleration, time);
   updateRotation(time);
}

/*********************************************
 * Satellite : MAKE DEFUNCT
 * Mark the satellite as no longer operational.
 *********************************************/
void Satellite::makeDefunct()
{
   defunct = true;
   beginUncontrolledSpin();
}

/*********************************************
 * Satellite : IS DEFUNCT
 * Determine whether the satellite is defunct.
 *********************************************/
bool Satellite::isDefunct() const
{
   return defunct;
}

/*********************************************
 * Satellite : BEGIN UNCONTROLLED SPIN
 * Begin uncontrolled rotation after the satellite becomes defunct.
 *********************************************/
void Satellite::beginUncontrolledSpin()
{
   uncontrolledRotationRate = 0.0;
}
