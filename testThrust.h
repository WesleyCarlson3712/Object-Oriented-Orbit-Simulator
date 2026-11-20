#pragma once
/***********************************************************************
 * Header File:
 *    Test Thrust : Test the Thrust class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Thrust
 ************************************************************************/

#pragma once

#include "thrust.h"
#include "unitTest.h"

 /*********************************************
  * TestThrust
  * Unit tests for the Thrust propulsion component.
  *********************************************/
class TestThrust : public UnitTest
{
public:
   void run();

private:
   void construct_default();
   void activate();
   void deactivate();
   void setMagnitude();
   void getAcceleration_inactive();
   void getAcceleration_activeFacingUp();
   void getAcceleration_activeFacingRight();
   void getAcceleration_activeFacingDown();
   void getAcceleration_activeFacingLeft();
   void getAcceleration_activeDiagonal();
};