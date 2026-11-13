/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 *****************************************************************/

#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"    // for POINT
#include "earth.h"
#include "satellite.h"
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
      satellite(SatelliteType::GPS,
                Position(0.0, 42164000.0),
                Velocity(-3100.0, 0.0),
                Angle(-Angle::PI / 2.0),
                0.0),
      earth()
   {
   }

   void update(double time)
   {
      satellite.update(time);
      earth.update(time);
   }

   void draw(ogstream& gout)
   {
      satellite.draw(gout);
      earth.draw(gout);
   }

private:
   Satellite satellite;
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
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulation* pSimulation = (Simulation*)p;

   (void)pUI;

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
   Simulation simulation;

   // set everything into action
   ui.run(callBack, &simulation);


   return 0;
}
