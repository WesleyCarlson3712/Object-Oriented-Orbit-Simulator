#include "earth.h"

#include "uiDraw.h"

Earth::Earth() :
   position(0.0, 0.0),
   orientation(),
   rotationRate(-2.0 * Angle::PI / (24.0 * 60.0 * 60.0))
{
}

void Earth::update(double time)
{
   orientation.add(rotationRate * time);
}

void Earth::draw(ogstream& out)
{
   out.drawEarth(position, orientation.getRadians());
}