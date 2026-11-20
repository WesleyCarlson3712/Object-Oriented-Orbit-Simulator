/*************************************************************
 * 1. Name:
 *      Wesley Carlson
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 *****************************************************************/

#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include "earth.h"
#include "satellite.h"
#include "gps.h"
#include "ship.h"
#include "test.h"

const double SIMULATION_SECONDS_PER_FRAME = 48.0;

/*************************************************************************
 * Simulation
 * Everything pertaining to the orbit simulation.
 *************************************************************************/
class Simulation
{
public:
   Simulation() :
      ship(Position(-42164000.0, 0.0),
           Velocity(0.0, 3100.0),
           Angle(Angle::PI / 2.0)),
      satellite(Position(0.0, 42164000.0),
                Velocity(-3100.0, 0.0),
                Angle(-Angle::PI / 2.0),
                -0.000072),
      earth()
   {
   }

   /**********************************************************************
    * HANDLE INPUT
    * Read user keyboard inputs and adjust ship orientation and thrust.
    **********************************************************************/
   void handleInput(const Interface* pUI)
   {
      if (!pUI)
         return;

      // Turning controls
      if (pUI->isLeft())
         ship.turn(-0.1);
      if (pUI->isRight())
         ship.turn(0.1);

      // Main thruster activation
      ship.setThrust(pUI->isUp() || pUI->isDown());

      // Fire weapon (stub)
      if (pUI->isSpace())
         ship.fire();
   }

   void update(double time)
   {
      ship.update(time);
      satellite.update(time);
      earth.update(time);
   }

   void draw(ogstream& gout)
   {
      ship.draw(gout);
      satellite.draw(gout);
      earth.draw(gout);
   }

private:
   Ship ship;
   GPS satellite;
   Earth earth;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   Simulation* pSimulation = (Simulation*)p;

   //
   // accept input
   //
   pSimulation->handleInput(pUI);

   //
   // perform all the game logic
   //
   pSimulation->update(SIMULATION_SECONDS_PER_FRAME);

   //
   // draw everything
   //
   Position pt;
   ogstream gout(pt);

   pSimulation->draw(gout);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Orbit Simulator",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Simulation simulation;

   // set everything into action
   ui.run(callBack, &simulation);

   return 0;
}
