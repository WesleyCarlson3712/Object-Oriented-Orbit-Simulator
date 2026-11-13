#pragma once

#include "spaceObject.h"
#include "unitTest.h"

class TestSpaceObject : public SpaceObject, public UnitTest
{
public:
   void update(double time) override
   {
      Acceleration acceleration = computeGravity();
      updatePosition(acceleration, time);
      updateVelocity(acceleration, time);
      updateRotation(time);
   }

   void draw(ogstream&) override {}

   std::vector<SpaceObject*> breakApart() override
   {
      return {};
   }

   void run()
   {
      construct_default();
      testDestroy();
      testRotate();
      testUpdateRotation();
      testCollidesWith();
      testUpdatePosition();
      testUpdateVelocity();
      testComputeGravity();

      report("SpaceObject");
   }

private:
   void construct_default()
   {
      TestSpaceObject object;

      assertEquals(object.position.getMetersX(), 0.0);
      assertEquals(object.position.getMetersY(), 0.0);
      assertEquals(object.velocity.getDX(), 0.0);
      assertEquals(object.velocity.getDY(), 0.0);
      assertEquals(object.radius, 0.0);
      assertUnit(object.alive);
      assertEquals(object.orientation.getRadians(), 0.0);
      assertEquals(object.rotationRate, 0.0);
   }

   void testDestroy()
   {
      TestSpaceObject object;
      object.destroy();

      assertUnit(!object.isAlive());
   }

   void testRotate()
   {
      TestSpaceObject object;
      object.rotate(0.75);

      assertEquals(object.getOrientation().getRadians(), 0.75);
   }

   void testUpdateRotation()
   {
      TestSpaceObject object;
      object.rotationRate = 0.5;
      object.updateRotation(4.0);

      assertEquals(object.getOrientation().getRadians(), 2.0);
   }

   void testCollidesWith()
   {
      TestSpaceObject first;
      TestSpaceObject second;
      first.position.setMeters(0.0, 0.0);
      second.position.setMeters(7.0, 0.0);
      first.radius = 5.0;
      second.radius = 3.0;

      assertUnit(first.collidesWith(second));

      second.position.setMeters(9.0, 0.0);
      assertUnit(!first.collidesWith(second));
   }

   void testUpdatePosition()
   {
      TestSpaceObject object;
      object.velocity = Velocity(10.0, 20.0);
      Acceleration acceleration(2.0, 4.0);

      object.updatePosition(acceleration, 3.0);

      assertEquals(object.position.getMetersX(), 39.0);
      assertEquals(object.position.getMetersY(), 78.0);
   }

   void testUpdateVelocity()
   {
      TestSpaceObject object;
      object.velocity = Velocity(10.0, 20.0);
      Acceleration acceleration(2.0, -4.0);

      object.updateVelocity(acceleration, 3.0);

      assertEquals(object.velocity.getDX(), 16.0);
      assertEquals(object.velocity.getDY(), 8.0);
   }

   void testComputeGravity()
   {
      TestSpaceObject object;
      object.position.setMeters(0.0, 1000.0);

      Acceleration acceleration = object.computeGravity();

      assertEqualsTolerance(acceleration.getDDX(), 0.0, 0.0001);
      assertEqualsTolerance(acceleration.getDDY(), -398600441.8, 1.0);
   }
};
