#pragma once

#include "velocity.h"
#include "unitTest.h"

/*******************************
 * TEST Velocity
 * A friend class for Velocity which contains the Velocity unit tests
 ********************************/
class TestVelocity : public UnitTest
{
public:
   void run()
   {
      construct_default();
      construct_nonDefault();
      getDX();
      getDY();
      getSpeed();
      setDX();
      setDY();
      addDX();
      addDY();
      add();

      report("Velocity");
   }

private:
   void construct_default()
   {
      Velocity velocity;
      assertEquals(velocity.dx, 0.0);
      assertEquals(velocity.dy, 0.0);
   }

   void construct_nonDefault()
   {
      Velocity velocity(-3100.0, 0.0);
      assertEquals(velocity.dx, -3100.0);
      assertEquals(velocity.dy, 0.0);
   }

   void getDX()
   {
      Velocity velocity;
      velocity.dx = 12.5;
      velocity.dy = -8.0;
      assertEquals(velocity.getDX(), 12.5);
      assertEquals(velocity.dy, -8.0);
   }

   void getDY()
   {
      Velocity velocity;
      velocity.dx = 12.5;
      velocity.dy = -8.0;
      assertEquals(velocity.dx, 12.5);
      assertEquals(velocity.getDY(), -8.0);
   }

   void getSpeed()
   {
      Velocity velocity(3.0, 4.0);
      assertEquals(velocity.getSpeed(), 5.0);
   }

   void setDX()
   {
      Velocity velocity(10.0, 20.0);
      velocity.setDX(-3.5);
      assertEquals(velocity.dx, -3.5);
      assertEquals(velocity.dy, 20.0);
   }

   void setDY()
   {
      Velocity velocity(10.0, 20.0);
      velocity.setDY(-3.5);
      assertEquals(velocity.dx, 10.0);
      assertEquals(velocity.dy, -3.5);
   }

   void addDX()
   {
      Velocity velocity(10.0, 20.0);
      velocity.addDX(-3.5);
      assertEquals(velocity.dx, 6.5);
      assertEquals(velocity.dy, 20.0);
   }

   void addDY()
   {
      Velocity velocity(10.0, 20.0);
      velocity.addDY(-3.5);
      assertEquals(velocity.dx, 10.0);
      assertEquals(velocity.dy, 16.5);
   }

   void add()
   {
      Velocity velocity(10.0, 20.0);
      velocity.add(2.0, -4.0, 3.0);
      assertEquals(velocity.dx, 16.0);
      assertEquals(velocity.dy, 8.0);
   }
};
