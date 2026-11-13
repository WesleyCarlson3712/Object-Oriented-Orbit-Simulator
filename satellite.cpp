#include "satellite.h"

#include "uiDraw.h"

/*********************************************
 * Satellite : CONSTRUCTOR
 * Initialize a satellite with its type and physical state.
 *********************************************/
Satellite::Satellite(SatelliteType type,
                     const Position& position,
                     const Velocity& velocity,
                     const Angle& orientation,
                     double rotationRate) :
   SpaceObject(),
   type(type),
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
 * Satellite : DRAW
 * Draw the satellite according to its type.
 *********************************************/
void Satellite::draw(ogstream& out)
{
   switch (type)
   {
   case SatelliteType::SPUTNIK:
      out.drawSputnik(position, orientation.getRadians());
      break;

   case SatelliteType::GPS:
      out.drawGPS(position, orientation.getRadians());
      break;

   case SatelliteType::HUBBLE:
      out.drawHubble(position, orientation.getRadians());
      break;

   case SatelliteType::CREW_DRAGON:
      out.drawCrewDragon(position, orientation.getRadians());
      break;

   case SatelliteType::STARLINK:
      out.drawStarlink(position, orientation.getRadians());
      break;
   }
}

/*********************************************
 * Satellite : BREAK APART
 * Return the objects created when the satellite breaks apart.
 *********************************************/
std::vector<SpaceObject*> Satellite::breakApart()
{
   return {};
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
