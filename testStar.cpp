/***********************************************************************
 * Source File:
 *    Test Star : Test the Star class
 * Author:
 *    Wesley Carlson
 * Summary:
 *    All the unit tests for Star
 ************************************************************************/

#include "testStar.h"
#include "uiDraw.h"

void TestStar::run()
{
   construct_default();
   construct_nonDefault();
   update_phase();
   update_phaseWrap();
   reset();
   draw();

   report("Star");
}

void TestStar::construct_default()
{
   Star star;
   assertEquals(star.position.getMetersX(), 0.0);
   assertEquals(star.position.getMetersY(), 0.0);
   assertEquals(star.phase, 0);
}

void TestStar::construct_nonDefault()
{
   Star star(1000.0, 1000.0);
   assertUnit(star.position.getPixelsX() >= -500.0 && star.position.getPixelsX() <= 500.0);
   assertUnit(star.position.getPixelsY() >= -500.0 && star.position.getPixelsY() <= 500.0);
}

void TestStar::update_phase()
{
   Star star;
   star.phase = 50;
   star.update();
   assertEquals(star.phase, 51);
}

void TestStar::update_phaseWrap()
{
   Star star;
   star.phase = 255;
   star.update();
   assertEquals(star.phase, 0);
}

void TestStar::reset()
{
   Star star;
   star.reset(800.0, 600.0);
   assertUnit(star.position.getPixelsX() >= -400.0 && star.position.getPixelsX() <= 400.0);
   assertUnit(star.position.getPixelsY() >= -300.0 && star.position.getPixelsY() <= 300.0);
}

void TestStar::draw()
{
   Star star;
   Position pt;
   ogstreamFake fake(pt);
   star.draw(fake);
   fake.str("");
   assertUnit(true);
}