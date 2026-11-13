/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"    // for POINT
#include "angle.h"
#include "satellite.h"
#include "test.h"
using namespace std;

const double SIMULATION_SECONDS_PER_FRAME = 48.0;
const double EARTH_ROTATION_PER_FRAME =
   -2.0 * Angle::PI * SIMULATION_SECONDS_PER_FRAME / (24.0 * 60.0 * 60.0);

/*************************************************************************
 * Simulation
 * Everything pertaining to the orbit simulation.
 *************************************************************************/
class Simulation
{
public:
   Simulation(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
      satellite()
   {
      angleEarth = 0.0;
      phaseStar = 0;
   }

   void update(double time)
   {
      satellite.update(time);
      angleEarth += EARTH_ROTATION_PER_FRAME;
      phaseStar++;
   }

   void draw(ogstream& gout)
   {
      satellite.draw(gout);

      Position ptEarth;
      ptEarth.setMeters(0.0, 0.0);
      gout.drawEarth(ptEarth, angleEarth);
   }

private:
   Position ptUpperRight;
   Satellite satellite;
   unsigned char phaseStar;
   double angleEarth;
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
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulation* pSimulation = (Simulation*)p;

   //
   // accept input
   //

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
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Simulation simulation(ptUpperRight);

   // set everything into action
   ui.run(callBack, &simulation);


   return 0;
}
