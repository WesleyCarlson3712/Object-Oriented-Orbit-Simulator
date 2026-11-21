#pragma once
/***********************************************************************
 * Header File:
 *    Test Star : Test the Star class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Star
 ************************************************************************/

#pragma once

#include "star.h"
#include "unitTest.h"

 /*********************************************
  * TestStar
  * Unit tests for the Star component.
  *********************************************/
class TestStar : public UnitTest
{
public:
   void run();

private:
   void construct_default();
   void construct_nonDefault();
   void update_phase();
   void update_phaseWrap();
   void reset();
   void draw();
};