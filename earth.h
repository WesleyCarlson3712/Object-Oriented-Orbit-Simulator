#pragma once

#include "angle.h"
#include "position.h"

class ogstream;
class TestEarth;

class Earth
{
   friend TestEarth;

public:
   Earth();

   void update(double time);
   void draw(ogstream& out);

private:
   Position position;
   Angle orientation;
   double rotationRate;
};