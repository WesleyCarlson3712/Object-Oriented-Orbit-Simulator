#pragma once

#include "spaceObject.h"
#include "unitTest.h"

class TestSpaceObject : public SpaceObject, public UnitTest
{
public:
   void update(double time) override;
   void draw(ogstream&) override;
   std::vector<SpaceObject*> breakApart() override;

   void run();

private:
   void construct_default();
   void testDestroy();
   void testRotate();
   void testUpdateRotation();
   void testCollidesWith();
   void testUpdatePosition();
   void testUpdateVelocity();
   void testComputeGravity();
};
