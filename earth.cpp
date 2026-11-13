#include "earth.h"

#include "uiDraw.h"

/*********************************************
 * Earth : CONSTRUCTOR
 * Initialize Earth at the origin with its normal rotation rate.
 *********************************************/
Earth::Earth() :
   position(0.0, 0.0),
   orientation(),
   rotationRate(-2.0 * Angle::PI / (24.0 * 60.0 * 60.0))
{
}

/*********************************************
 * Earth : UPDATE
 * Rotate Earth through one time step.
 *********************************************/
void Earth::update(double time)
{
   orientation.add(rotationRate * time);
}

/*********************************************
 * Earth : DRAW
 * Draw Earth at its current orientation.
 *********************************************/
void Earth::draw(ogstream& out)
{
   out.drawEarth(position, orientation.getRadians());
}