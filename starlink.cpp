/***********************************************************************
 * Source File:
 *    Starlink : Represents a Starlink satellite
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Implementation of a Starlink satellite.
 ************************************************************************/

#include "starlink.h"
#include "uiDraw.h"

 /*********************************************
  * Starlink : DEFAULT CONSTRUCTOR
  *********************************************/
Starlink::Starlink() :
   Satellite()
{
   radius = 6.0;
}

/*********************************************
 * Starlink : NON-DEFAULT CONSTRUCTOR
 *********************************************/
Starlink::Starlink(const Position& position,
   const Velocity& velocity,
   const Angle& orientation,
   double rotationRate) :
   Satellite(position, velocity, orientation, rotationRate)
{
   radius = 6.0;
}

/*********************************************
 * Starlink : DRAW
 * Draw Starlink on the screen.
 *********************************************/
void Starlink::draw(ogstream& out)
{
   out.drawStarlink(position, orientation.getRadians());
}

/*********************************************
 * Starlink : BREAK APART
 * Stub for future collision handling.
 *********************************************/
std::vector<SpaceObject*> Starlink::breakApart()
{
   return {};
}