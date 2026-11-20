/***********************************************************************
 * Header File:
 *    Test Earth : Test the Earth class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Declarations of unit tests for Earth.
 ************************************************************************/

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