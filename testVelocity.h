#pragma once

#include "velocity.h"
#include "unitTest.h"

/*******************************
 * TEST Velocity
 * A friend class for Velocity which contains the Velocity unit tests
 ********************************/
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
   void getAngle();
   void setDX();
   void setDY();
   void addDX();
   void addDY();
   void add();
   void addAcceleration();
};
