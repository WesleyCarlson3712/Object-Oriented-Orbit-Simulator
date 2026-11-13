#pragma once

#include "direction.h"
#include "unitTest.h"

/*******************************
 * TEST Direction
 * A friend class for Direction which contains the Direction unit tests
 ********************************/
class TestDirection : public UnitTest
{
public:
   void run()
   {
      // Constructors
      construct_default();
      construct_nonDefault();

      // Getters
      getRadians();
      getDegrees();

      // Setters
      setRadians();
      setDegrees();

      report("Direction");
   }

private:
   void construct_default()
   {
      Direction direction;

      assertEquals(direction.radians, 0.0);
   }

   void construct_nonDefault()
   {
      Direction direction(Direction::PI / 2.0);

      assertEquals(direction.radians, Direction::PI / 2.0);
   }

   void getRadians()
   {
      Direction direction;
      direction.radians = Direction::PI / 4.0;

      assertEquals(direction.getRadians(), Direction::PI / 4.0);
   }

   void getDegrees()
   {
      Direction direction(Direction::PI / 2.0);

      assertEquals(direction.getDegrees(), 90.0);
   }

   void setRadians()
   {
      Direction direction;
      direction.setRadians(Direction::PI);

      assertEquals(direction.radians, Direction::PI);
      assertEquals(direction.getDegrees(), 180.0);
   }

   void setDegrees()
   {
      Direction direction;
      direction.setDegrees(270.0);

      assertEquals(direction.radians, Direction::PI * 1.5);
      assertEquals(direction.getDegrees(), 270.0);
   }
};
