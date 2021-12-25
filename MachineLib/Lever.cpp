/**
 * @file Lever.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"

#include <cmath>

#include "Lever.h"
#include "Component.h"
#include "Polygon.h"
#include "RotationSource.h"
#include "RotationSink.h"
#include "RodSink.h"
#include "INegotiator.h"
#include "Rod.h"

using namespace std;

/// The multiplier for the lever
const double multiplier = 0.128;

/// the M_PI * 2 value
const double PI2 = M_PI * 2;

/**
 * Constructor
 * @param leverLength the length of the lever
 */
Lever::Lever(int leverLength) : mRodSink(this, this)
{
    mLeverLength = leverLength;

    // Making the rectangle
    Rectangle(int(-mLeverLength/2),int(multiplier*mLeverLength/2),
            int(mLeverLength),int(multiplier*mLeverLength));
}

/**
 * Draws the lever of the machine
 * @param graphics graphics to draw on
 * @param x x position
 * @param y y position
 */
void Lever::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x, y);
}

/**
 * Update the component
 * @param time the current time
 */
void Lever::Update(double time)
{
    mRotationSource.RotationSinking(GetRotation());
}
/**
 * Negotiator between the rod and the lever
 * @param rod the rod attached to lever
 */
void Lever::Negotiate(Rod* rod)
{
    // Rod position
    double x1 = rod->GetPosition().x;
    double y1 = rod->GetPosition().y;
    double b = rod->GetRodLength();

    // Component position
    double x2 = GetPosition().x;
    double y2 = GetPosition().y;
    double a = mDriveLength;

    // Finding angle for the rod
    double c = sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
    double beta = atan2(-(y2-y1), (x2-x1));
    double x = (((b*b) + (c*c) - (a*a))/(2*b*c));
    double gamma = acos(x);
    double theta = beta - gamma;

    // the M_PI * 2 value
    const double PI2 = M_PI * 2;
    // Setting the rod angle
    rod->SetRotation(-theta/(PI2));

    // Finding the angle for lever
    double x3 = x1 + b*cos(-theta);
    double y3 = y1 + b*sin(-theta);

    double alpha = atan2((y3-y2),(x3-x2));

    // Setting the lever angle
    SetRotation(alpha/(PI2));

    // Finding the position for the rod that is attached to other end
    double x4 = x2 + -a * cos(alpha) - 2;
    double y4 = y2 + -a * sin(alpha);

    // Setting the position of the sink
    mPositionSource.SetPositions(wxPoint(int(x4),int(y4)));
}
