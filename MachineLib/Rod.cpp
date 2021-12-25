/**
 * @file Rod.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"
#include <cmath>
#include "Rod.h"
#include "Component.h"
#include "Polygon.h"

/**
 * Constructor
 * @param rodLength the length of the rod
 * @param rodWidth the width of the rod
 */
Rod::Rod(int rodLength, int rodWidth) : mRodLength(rodLength)
{
    // Setting the rod width
    mRodWidth = rodWidth;

    // Setting the position sink
    mSink.SetComponent(this);

    Rectangle(0,0,mRodLength,mRodWidth);
}

/**
 * Draws the rod
 * @param graphics the graphics to draw on
 * @param x the x position
 * @param y the y position
 */
void Rod::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    // Negotiating for piston and rod
    mRodSource.RodNegotiating(this);

    Component::Draw(graphics,x,y);
}

/**
 * Updates the rod component
 * @param time the current time
 */
void Rod::Update(double time)
{
    // Updating the piston and lever
    mRodSource.RodNegotiating(this);
}

