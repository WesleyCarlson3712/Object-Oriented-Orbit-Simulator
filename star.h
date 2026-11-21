#pragma once
/***********************************************************************
 * Header File:
 *    Star : Represents a twinkling background star
 * Author:
 *    Wesley Carlson
 * Summary:
 *    A star in the background that twinkles by advancing phase.
 ************************************************************************/

#pragma once

#include "position.h"

class ogstream;
class TestStar;

/*********************************************
 * Star
 * Represents a twinkling background star.
 *********************************************/
class Star
{
   friend TestStar;

public:
   Star();
   Star(double width, double height);

   void reset(double width, double height);
   void update();
   void draw(ogstream& out);

   const Position& getPosition() const { return position; }
   unsigned char getPhase() const { return phase; }

private:
   Position position;
   unsigned char phase;
};