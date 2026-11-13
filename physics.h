#pragma once

#include "acceleration.h"
#include "position.h"
#include "velocity.h"

/*********************************************************
 * PHYSICS CONSTANTS
 *********************************************************/
constexpr double EARTH_GRAVITATIONAL_PARAMETER = 3.986004418e14;

/*********************************************************
 * GRAVITY FROM DISTANCE
 * Determine the acceleration caused by Earth's gravity at
 * a distance from the center of Earth.
 *********************************************************/
double gravityFromDistance(double distance);

/*********************************************************
 * COMPUTE GRAVITY
 * Determine the horizontal and vertical acceleration caused
 * by Earth's gravity at a position relative to Earth's center.
 *********************************************************/
Acceleration computeGravity(const Position& position);

/*********************************************************
 * UPDATE POSITION
 * Update position using velocity and acceleration.
 *********************************************************/
void updatePosition(Position& position, const Velocity& velocity,
                    const Acceleration& acceleration, double time);

/*********************************************************
 * UPDATE VELOCITY
 * Update velocity using acceleration over time.
 *********************************************************/
void updateVelocity(Velocity& velocity, const Acceleration& acceleration,
                    double time);

/*********************************************************
 * PHYSICS STEP
 * Advance an orbit by one simulation time step.
 *********************************************************/
void physicsStep(Position& position, Velocity& velocity, double time);
