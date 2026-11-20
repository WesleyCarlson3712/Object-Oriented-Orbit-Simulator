#pragma once

#include "earth.h"
#include "unitTest.h"

class TestEarth : public UnitTest
{
public:
   void run();

private:
   void construct_default();
   void update();
};