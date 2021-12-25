/**
 * @file Shape.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"
#include "Shape.h"
#include "Component.h"

/**
 * Constructor
 */
Shape::Shape()
{
    mSink.SetComponent(this);
}

/**
* Draws the basic shape of the machine
* @param graphics graphics to draw on
* @param x x position
* @param y y position
*/
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x, y);
}

/**
 * Updates the component
 * @param time the current time
 */
void Shape::Update(double time)
{

}