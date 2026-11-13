#pragma once

#include "angle.h"
#include "position.h"

class ogstream;
class TestEarth;

/*********************************************
 * Earth
 * Represents the Earth in the orbit simulation.
 *********************************************/
class Earth
{
   friend TestEarth;

public:
   /*********************************************
    * CONSTRUCTOR
    * Initialize Earth at the origin with its normal rotation rate.
    *********************************************/
   Earth();

   /*********************************************
    * UPDATE
    * Rotate Earth through one time step.
    *********************************************/
   void update(double time);

   /*********************************************
    * DRAW
    * Draw Earth at its current orientation.
    *********************************************/
   void draw(ogstream& out);

private:
   Position position;
   Angle orientation;
   double rotationRate;
};