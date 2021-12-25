/**
 * @file Piston.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"
#include "Piston.h"
#include "Component.h"

/**
 * Constructor for the piston
 */
Piston::Piston() : mRodSink(this, this)
{

}

/**
 * Draws the piston of the machine
 * @param graphics graphics to draw on
 * @param x x position
 * @param y y position
 */
void Piston::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x, y);
}

/**
 * Negotiator between the rod and the lever
 * @param rod the rod attached to lever
 */
void Piston::Negotiate(Rod* rod)
{
    // Finding the piston position
    double x2 = GetPosition().x;

    // Finding the rod position
    double x1 = rod->GetPosition().x;
    double y1 = rod->GetPosition().y;
    double a = rod->GetRodLength();

    // Finding the angle of rotation of the rod
    double alpha = asin((x2 - x1) / a);
    double beta = M_PI / 2 - alpha;
    rod->SetRotation( beta / (M_PI * 2));

    // Finding the position of the piston
    double y2 = y1 + a * cos(alpha);
    SetPosition(wxPoint(int(x2), int(y2)));
}

