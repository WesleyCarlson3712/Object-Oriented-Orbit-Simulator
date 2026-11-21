/***********************************************************************
 * Source File:
 *    Star : Represents a twinkling background star
 * Author:
 *    Wesley Carlson
 * Summary:
 *    Implementation of the background star.
 ************************************************************************/

#include "star.h"
#include "uiDraw.h"

 /*********************************************
  * Star : DEFAULT CONSTRUCTOR
  * Initialize star at origin with phase 0.
  *********************************************/
Star::Star() :
   position(),
   phase(0)
{
}

/*********************************************
 * Star : NON-DEFAULT CONSTRUCTOR
 * Initialize and randomize position and phase.
 *********************************************/
Star::Star(double width, double height) :
   position(),
   phase(0)
{
   reset(width, height);
}

/*********************************************
 * Star : RESET
 * Randomize position across width and height,
 * and randomize initial phase.
 *********************************************/
void Star::reset(double width, double height)
{
   int minX = static_cast<int>(-width / 2.0);
   int maxX = static_cast<int>(width / 2.0);
   int minY = static_cast<int>(-height / 2.0);
   int maxY = static_cast<int>(height / 2.0);

   position.setPixelsX(random(minX, maxX));
   position.setPixelsY(random(minY, maxY));
   phase = static_cast<unsigned char>(random(0, 255));
}

/*********************************************
 * Star : UPDATE
 * Advance the star's twinkle phase.
 *********************************************/
void Star::update()
{
   phase++;
}

/*********************************************
 * Star : DRAW
 * Draw the star using the graphics stream.
 *********************************************/
void Star::draw(ogstream& out)
{
   out.drawStar(position, phase);
}