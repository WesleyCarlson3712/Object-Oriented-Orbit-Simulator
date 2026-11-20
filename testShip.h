#pragma once
/***********************************************************************
 * Header File:
 *    Test Ship : Test the Ship class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Ship
 ************************************************************************/

#pragma once

#include "ship.h"
#include "unitTest.h"

 /*********************************************
  * TestShip
  * Unit tests for the Ship class.
  *********************************************/
class TestShip : public UnitTest
{
public:
   void run();

private:
   void construct_default();
   void construct_nonDefault();
   void setThrust();
   void turn();
   void thrust_method();
   void update_coasting();
   void update_thrusting();
   void update_rotation();
   void breakApart();
   void draw_thrustOff();
   void draw_thrustOn();
};