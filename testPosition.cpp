/***********************************************************************
 * Source File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/

#include "testPosition.h"

void TestPosition::run()
{
   // Constructors
   construct_default();
   construct_nonDefault();
   construct_copy();
   assign();

   // Setters
   setMetersX();
   setMetersY();

   // Getters
   getMetersX();
   getMetersY();

   report("Position");
}

void TestPosition::construct_default()
{
   double metersFromPixels = Position::metersFromPixels;
   Position::metersFromPixels = 99.9;

   Position pos;

   assertEquals(pos.x, 0.0);
   assertEquals(pos.y, 0.0);
   assertEquals(pos.metersFromPixels, 99.9);

   Position::metersFromPixels = metersFromPixels;
}

void TestPosition::construct_nonDefault()
{
   double metersFromPixels = Position::metersFromPixels;
   Position::metersFromPixels = 99.9;
   double x = 120.0;
   double y = 360.0;

   Position pos(x, y);

   assertEquals(pos.x, 120.0);
   assertEquals(pos.y, 360.0);
   assertEquals(pos.metersFromPixels, 99.9);
   assertEquals(x, 120.0);
   assertEquals(y, 360.0);

   Position::metersFromPixels = metersFromPixels;
}

void TestPosition::construct_copy()
{
   double metersFromPixels = Position::metersFromPixels;
   Position::metersFromPixels = 99.9;
   Position posRHS;
   posRHS.x = 1234.5;
   posRHS.y = 6789.0;

   Position pos(posRHS);

   assertEquals(posRHS.x, 1234.5);
   assertEquals(posRHS.y, 6789.0);
   assertEquals(posRHS.metersFromPixels, 99.9);
   assertEquals(pos.x, 1234.5);
   assertEquals(pos.y, 6789.0);
   assertEquals(pos.metersFromPixels, 99.9);

   Position::metersFromPixels = metersFromPixels;
}

void TestPosition::assign()
{
   double metersFromPixels = Position::metersFromPixels;
   Position::metersFromPixels = 99.9;
   Position posLHS;
   posLHS.x = -99.9;
   posLHS.y = -88.8;
   Position posRHS;
   posRHS.x = 24.68;
   posRHS.y = -13.57;

   posLHS = posRHS;

   assertEquals(posRHS.x, 24.68);
   assertEquals(posRHS.y, -13.57);
   assertEquals(posRHS.metersFromPixels, 99.9);
   assertEquals(posLHS.x, 24.68);
   assertEquals(posLHS.y, -13.57);
   assertEquals(posLHS.metersFromPixels, 99.9);

   Position::metersFromPixels = metersFromPixels;
}

void TestPosition::getMetersX()
{
   double metersFromPixels = Position::metersFromPixels;
   Position::metersFromPixels = 99.9;
   Position pos;
   pos.x = 4500.0;
   pos.y = 2500.0;

   double x = pos.getMetersX();

   assertEquals(x, 4500.0);
   assertEquals(pos.x, 4500.0);
   assertEquals(pos.y, 2500.0);
   assertEquals(pos.metersFromPixels, 99.9);

   Position::metersFromPixels = metersFromPixels;
}

void TestPosition::getMetersY()
{
   double metersFromPixels = Position::metersFromPixels;
   Position::metersFromPixels = 99.9;
   Position pos;
   pos.x = 4500.0;
   pos.y = 2500.0;

   double y = pos.getMetersY();

   assertEquals(y, 2500.0);
   assertEquals(pos.x, 4500.0);
   assertEquals(pos.y, 2500.0);
   assertEquals(pos.metersFromPixels, 99.9);

   Position::metersFromPixels = metersFromPixels;
}

void TestPosition::setMetersX()
{
   double metersFromPixels = Position::metersFromPixels;
   Position::metersFromPixels = 99.9;
   Position pos;
   pos.x = 999.9;
   pos.y = 888.8;

   pos.setMetersX(123.4);

   assertEquals(pos.x, 123.4);
   assertEquals(pos.y, 888.8);
   assertEquals(pos.metersFromPixels, 99.9);

   Position::metersFromPixels = metersFromPixels;
}

void TestPosition::setMetersY()
{
   double metersFromPixels = Position::metersFromPixels;
   Position::metersFromPixels = 99.9;
   Position pos;
   pos.x = 999.9;
   pos.y = 888.8;

   pos.setMetersY(123.4);

   assertEquals(pos.x, 999.9);
   assertEquals(pos.y, 123.4);
   assertEquals(pos.metersFromPixels, 99.9);

   Position::metersFromPixels = metersFromPixels;
}