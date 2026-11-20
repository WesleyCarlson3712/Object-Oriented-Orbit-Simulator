#pragma once

#include "acceleration.h"
#include "unitTest.h"

/***********************************************************************
 * Header File:
 *    Test Acceleration : Test the Acceleration class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Acceleration
 ************************************************************************/
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
   void getMagnitude_zero();
   void getMagnitude_negative();
   void setDDX();
   void setDDY();
   void add();
   void add_cancelling();
};