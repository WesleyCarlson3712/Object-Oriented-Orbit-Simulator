/***********************************************************************
 * Source File:
 *    Sputnik : Represents the Sputnik satellite
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Implementation of the Sputnik satellite.
 ************************************************************************/

#include "sputnik.h"
#include "uiDraw.h"

 /*********************************************
  * Sputnik : DEFAULT CONSTRUCTOR
  *********************************************/
Sputnik::Sputnik() :
   Satellite()
{
   radius = 4.0;
}

/*********************************************
 * Sputnik : NON-DEFAULT CONSTRUCTOR
 *********************************************/
Sputnik::Sputnik(const Position& position,
   const Velocity& velocity,
   const Angle& orientation,
   double rotationRate) :
   Satellite(position, velocity, orientation, rotationRate)
{
   radius = 4.0;
}

/*********************************************
 * Sputnik : DRAW
 * Draw Sputnik on the screen.
 *********************************************/
void Sputnik::draw(ogstream& out)
{
   out.drawSputnik(position, orientation.getRadians());
}

/*********************************************
 * Sputnik : BREAK APART
 * Stub for future collision handling.
 *********************************************/
std::vector<SpaceObject*> Sputnik::breakApart()
{
   return {};
}