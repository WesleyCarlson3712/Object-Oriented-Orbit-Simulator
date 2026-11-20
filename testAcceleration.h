#pragma once

#include "acceleration.h"
#include "unitTest.h"

class TestAcceleration : public UnitTest
{
public:
   void run();

private:
   void construct_default();
   void construct_nonDefault();
   void getDDX();
   void getDDY();
   void getMagnitude();
   void setDDX();
   void setDDY();
   void add();
};