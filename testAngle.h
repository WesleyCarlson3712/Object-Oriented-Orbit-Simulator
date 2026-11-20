/***********************************************************************
 * Header File:
 *    Test Angle : Test the Angle class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Declarations of unit tests for Angle.
 ************************************************************************/

#pragma once

#include "angle.h"
#include "unitTest.h"

/*******************************
 * TEST Angle
 * A friend class for Angle which contains the Angle unit tests
 ********************************/
class TestAngle : public UnitTest
{
public:
   void run();

private:
   void construct_default();
   void construct_nonDefault();

   // Getters
   void getRadians();
   void getDegrees();
   void getDx();
   void getDy();

   // Setters
   void setRadians();
   void setDegrees();
   void setDxDy();
   void add();
};
