#pragma once
#pragma once

#include "acceleration.h"
#include "unitTest.h"

class TestAcceleration : public UnitTest
{
public:
   void run()
   {
      construct_default();
      construct_nonDefault();
      getDDX();
      getDDY();
      getMagnitude();
      setDDX();
      setDDY();
      add();

      report("Acceleration");
   }

private:
   void construct_default()
   {
      Acceleration acceleration;

      assertEquals(acceleration.ddx, 0.0);
      assertEquals(acceleration.ddy, 0.0);
   }

   void construct_nonDefault()
   {
      Acceleration acceleration(3.0, 4.0);

      assertEquals(acceleration.ddx, 3.0);
      assertEquals(acceleration.ddy, 4.0);
   }

   void getDDX()
   {
      Acceleration acceleration(3.0, 4.0);

      assertEquals(acceleration.getDDX(), 3.0);
   }

   void getDDY()
   {
      Acceleration acceleration(3.0, 4.0);

      assertEquals(acceleration.getDDY(), 4.0);
   }

   void getMagnitude()
   {
      Acceleration acceleration(3.0, 4.0);

      assertEquals(acceleration.getMagnitude(), 5.0);
   }

   void setDDX()
   {
      Acceleration acceleration(3.0, 4.0);
      acceleration.setDDX(-2.0);

      assertEquals(acceleration.ddx, -2.0);
      assertEquals(acceleration.ddy, 4.0);
   }

   void setDDY()
   {
      Acceleration acceleration(3.0, 4.0);
      acceleration.setDDY(-2.0);

      assertEquals(acceleration.ddx, 3.0);
      assertEquals(acceleration.ddy, -2.0);
   }

   void add()
   {
      Acceleration acceleration(3.0, 4.0);
      Acceleration rhs(2.0, -1.0);

      acceleration.add(rhs);

      assertEquals(acceleration.ddx, 5.0);
      assertEquals(acceleration.ddy, 3.0);
   }
};