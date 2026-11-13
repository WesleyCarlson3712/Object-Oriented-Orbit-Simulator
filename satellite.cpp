#include "satellite.h"

#include "uiDraw.h"

Satellite::Satellite(SatelliteType type) :
   SpaceObject(),
   type(type),
   defunct(false),
   uncontrolledRotationRate(0.0)
{
   if (type == SatelliteType::GPS)
   {
      position.setMeters(0.0, 42164000.0);
      velocity = Velocity(-3100.0, 0.0);
   }
}

void Satellite::update(double time)
{
   if (!isAlive())
      return;

   Acceleration acceleration = computeGravity();

   updatePosition(acceleration, time);
   updateVelocity(acceleration, time);
   updateRotation(time);
}

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

std::vector<SpaceObject*> Satellite::breakApart()
{
   return {};
}

void Satellite::makeDefunct()
{
   defunct = true;
   beginUncontrolledSpin();
}

bool Satellite::isDefunct() const
{
   return defunct;
}

void Satellite::beginUncontrolledSpin()
{
   uncontrolledRotationRate = 0.0;
}