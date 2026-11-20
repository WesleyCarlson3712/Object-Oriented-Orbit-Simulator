/*************************************************************
 * 1. Name:
 *      Wesley Carlson
 * 2. Assignment Name:
 *      Lab 09: Orbit One Satellite (Full Orbit Simulator Demonstration)
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth with Dream Chaser ship.
 *****************************************************************/

#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include "earth.h"
#include "satellite.h"
#include "gps.h"
#include "sputnik.h"
#include "hubble.h"
#include "crewDragon.h"
#include "starlink.h"
#include "ship.h"
#include "test.h"
#include <vector>

const double SIMULATION_SECONDS_PER_FRAME = 48.0;

/*************************************************************************
 * Simulation
 * Everything pertaining to the orbit simulation.
 *************************************************************************/
class Simulation
{
public:
   Simulation() :
      ship(Position(-450.0 * 128000.0, 450.0 * 128000.0),
           Velocity(0.0, -2000.0),
           Angle(-3.0 * Angle::PI / 4.0)),
      earth()
   {
      createInitialObjects();
   }

   ~Simulation()
   {
      for (Satellite* pSatellite : satellites)
         delete pSatellite;
      satellites.clear();
   }

   /**********************************************************************
    * CREATE INITIAL OBJECTS
    * Instantiate all satellites according to design specifications.
    **********************************************************************/
   void createInitialObjects()
   {

      // Sputnik: elliptical, retrograde orbit
      satellites.push_back(new Sputnik(
         Position(-36515095.13, 21082000.0),
         Velocity(2050.0, 2684.68)));

      // 6 GPS Satellites in 20,180 km orbit (always facing Earth)
      // 1. (0.0 m, 26,560,000.0 m)
      satellites.push_back(new GPS(
         Position(0.0, 26560000.0),
         Velocity(-3880.0, 0.0)));

      // 2. (23,001,634.72 m, 13,280,000.0 m)
      satellites.push_back(new GPS(
         Position(23001634.72, 13280000.0),
         Velocity(-1940.00, 3360.18)));

      // 3. (23,001,634.72 m, -13,280,000.0 m)
      satellites.push_back(new GPS(
         Position(23001634.72, -13280000.0),
         Velocity(1940.00, 3360.18)));

      // 4. (0.0 m, -26,560,000.0 m)
      satellites.push_back(new GPS(
         Position(0.0, -26560000.0),
         Velocity(3880.0, 0.0)));

      // 5. (-23,001,634.72 m, -13,280,000.0 m)
      satellites.push_back(new GPS(
         Position(-23001634.72, -13280000.0),
         Velocity(1940.00, -3360.18)));

      // 6. (-23,001,634.72 m, 13,280,000.0 m)
      satellites.push_back(new GPS(
         Position(-23001634.72, 13280000.0),
         Velocity(-1940.00, -3360.18)));

      // Hubble Space Telescope in GEO
      satellites.push_back(new Hubble(
         Position(0.0, -42164000.0),
         Velocity(3100.0, 0.0)));

      // SpaceX Crew Dragon in LEO
      satellites.push_back(new CrewDragon(
         Position(0.0, 8000000.0),
         Velocity(-7900.0, 0.0)));

      // SpaceX Starlink in VLEO
      satellites.push_back(new Starlink(
         Position(0.0, -13020000.0),
         Velocity(5800.0, 0.0)));
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

      // Main thruster activation (down or up arrow)
      ship.setThrust(pUI->isUp() || pUI->isDown());

      // Fire weapon (stub)
      if (pUI->isSpace())
         ship.fire();
   }

   void update(double time)
   {

      ship.update(time);

      for (Satellite* pSatellite : satellites)
         pSatellite->update(time);

      earth.update(time);
   }

   void draw(ogstream& gout)
   {

      earth.draw(gout);

      for (Satellite* pSatellite : satellites)
         pSatellite->draw(gout);

      ship.draw(gout);
   }

private:
   Ship ship;
   Earth earth;
   std::vector<Satellite*> satellites;
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
