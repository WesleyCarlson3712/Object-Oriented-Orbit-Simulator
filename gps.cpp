/***********************************************************************
 * Source File:
 *    GPS : Represents a GPS satellite
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Implementation of the GPS satellite.
 ************************************************************************/

#include "gps.h"
#include "uiDraw.h"
#include <cmath>

 /*********************************************
  * GPS : DEFAULT CONSTRUCTOR
  * Defaults to standard geostationary orbit.
  *********************************************/
GPS::GPS() :
   Satellite(Position(0.0, 42164000.0),
      Velocity(-3100.0, 0.0),
      Angle(-Angle::PI / 2.0),
      -0.000072)
{
   radius = 12.0;
}

/*********************************************
 * GPS : NON-DEFAULT CONSTRUCTOR
 *********************************************/
GPS::GPS(const Position& position,
   const Velocity& velocity,
   const Angle& orientation,
   double rotationRate) :
   Satellite(position, velocity, orientation, rotationRate)
{
   radius = 12.0;
   if (!defunct && (position.getMetersX() != 0.0 || position.getMetersY() != 0.0))
      this->orientation.setRadians(std::atan2(position.getMetersY(), -position.getMetersX()));
}

/*********************************************
 * GPS : UPDATE
 * Advance GPS through physics and maintain
 * Earth-facing orientation unless defunct.
 *********************************************/
void GPS::update(double time)
{
   Satellite::update(time);
   if (!isDefunct())
      orientation.setRadians(std::atan2(position.getMetersY(), -position.getMetersX()));
}

/*********************************************
 * GPS : DRAW
 * Draw GPS satellite on the screen.
 *********************************************/
void GPS::draw(ogstream& out)
{
   out.drawGPS(position, orientation.getRadians());
}

/*********************************************
 * GPS : BREAK APART
 * Stub for future collision handling.
 *********************************************/
std::vector<SpaceObject*> GPS::breakApart()
{
   return {};
}