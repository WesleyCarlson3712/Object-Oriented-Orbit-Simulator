#pragma once

#include "satellite.h"
#include "unitTest.h"

class TestSatellite : public Satellite, public UnitTest
{
public:
   TestSatellite();

   void run();

private:
   void construct_default();
   void update();
   void makeDefunct();
   void testBreakApart();
};