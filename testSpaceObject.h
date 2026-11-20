#pragma once

#include "spaceObject.h"
#include "unitTest.h"

/***********************************************************************
 * Header File:
 *    Test SpaceObject : Test the SpaceObject class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for SpaceObject, acting as a test double.
 ************************************************************************/
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

   // Physics: Inertia
   void testInertia_constantVelocity();
   void testInertia_atRest();

   // Physics: Position
   void testUpdatePosition_combined();
   void testUpdatePosition_zeroVelocity();
   void testUpdatePosition_zeroAcceleration();
   void testUpdatePosition_negative();

   // Physics: Velocity
   void testUpdateVelocity_combined();
   void testUpdateVelocity_zeroAcceleration();
   void testUpdateVelocity_deceleration();
   void testUpdateVelocity_negative();

   // Physics: Gravity
   void testComputeGravity_nearSurface();
   void testComputeGravity_geostationaryY();
   void testComputeGravity_geostationaryX();
   void testComputeGravity_negativeQuadrant();
   void testComputeGravity_diagonal();

   // Physics: Full Simulation Step
   void testUpdate_fullStep();
};
