/**
 * @file Component.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"

#include "Component.h"
#include "ActualMachine.h"
#include "MachineDerived.h"

using namespace std;

/**
 * Constructor
 */
Component::Component()
{
}

/**
 * Updates the components
 * @param time the current time
 */
void Component::Update(double time)
{
    mTime = time;
}

/**
 * Draws the component of the machine
 * @param graphics graphics to draw on
 * @param x x position
 * @param y y position
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    DrawPolygon(graphics, x + mPosition.x, mPosition.y + y );
}
