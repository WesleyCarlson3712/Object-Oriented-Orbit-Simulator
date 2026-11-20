#pragma once

#include "velocity.h"
#include "unitTest.h"

/***********************************************************************
 * Header File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Velocity
 ************************************************************************/
class TestVelocity : public UnitTest
{
public:
   void run();

private:
   void construct_default();
   void construct_nonDefault();
   void getDX();
   void getDY();
   void getSpeed();
   void getSpeed_zero();
   void getSpeed_negative();
   void getAngle();
   void setDX();
   void setDY();
   void addDX();
   void addDY();
   void add();
   void add_zeroAcceleration();
   void add_negative();
   void addAcceleration();
};
