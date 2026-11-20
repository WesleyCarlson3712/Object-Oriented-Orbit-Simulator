/***********************************************************************
 * Source File:
 *    CrewDragon : Represents the Crew Dragon spacecraft
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Implementation of the Crew Dragon spacecraft.
 ************************************************************************/

#include "crewDragon.h"
#include "uiDraw.h"

 /*********************************************
  * CrewDragon : DEFAULT CONSTRUCTOR
  *********************************************/
CrewDragon::CrewDragon() :
   Satellite()
{
   radius = 7.0;
}

/*********************************************
 * CrewDragon : NON-DEFAULT CONSTRUCTOR
 *********************************************/
CrewDragon::CrewDragon(const Position& position,
   const Velocity& velocity,
   const Angle& orientation,
   double rotationRate) :
   Satellite(position, velocity, orientation, rotationRate)
{
   radius = 7.0;
}

/*********************************************
 * CrewDragon : DRAW
 * Draw Crew Dragon on the screen.
 *********************************************/
void CrewDragon::draw(ogstream& out)
{
   out.drawCrewDragon(position, orientation.getRadians());
}

/*********************************************
 * CrewDragon : BREAK APART
 * Stub for future collision handling.
 *********************************************/
std::vector<SpaceObject*> CrewDragon::breakApart()
{
   return {};
}