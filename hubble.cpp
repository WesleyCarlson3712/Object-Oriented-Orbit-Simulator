/***********************************************************************
 * Source File:
 *    Hubble : Represents the Hubble Space Telescope
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Implementation of the Hubble Space Telescope.
 ************************************************************************/

#include "hubble.h"
#include "uiDraw.h"

 /*********************************************
  * Hubble : DEFAULT CONSTRUCTOR
  *********************************************/
Hubble::Hubble() :
   Satellite()
{
   radius = 10.0;
}

/*********************************************
 * Hubble : NON-DEFAULT CONSTRUCTOR
 *********************************************/
Hubble::Hubble(const Position& position,
   const Velocity& velocity,
   const Angle& orientation,
   double rotationRate) :
   Satellite(position, velocity, orientation, rotationRate)
{
   radius = 10.0;
}

/*********************************************
 * Hubble : DRAW
 * Draw Hubble on the screen.
 *********************************************/
void Hubble::draw(ogstream& out)
{
   out.drawHubble(position, orientation.getRadians());
}

/*********************************************
 * Hubble : BREAK APART
 * Stub for future collision handling.
 *********************************************/
std::vector<SpaceObject*> Hubble::breakApart()
{
   return {};
}