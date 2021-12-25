/**
 * @file Gear.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"

#include <math.h>
#include "Gear.h"

using namespace std;

/// Depth of a tooth in pixels
const double ToothDepth = 5;

/// Width of a tooth at the top as fraction of tooth pitch
const double ToothWidth = 0.33;

/// Fraction of pitch where the tooth slopes up or down
const double ToothSlope = 0.1;

/// The angle for our gear
const double PI2 = M_PI * 2;

/**
 * Constructor
 * @param radius radius of the gear
 * @param numTeeth the number of teeth in our gear
 */
Gear::Gear(int radius, int numTeeth)
{
    // Setting the gear as a rotation sink
    mRotationSink.SetComponent(this);

    mTeeth = numTeeth;

    // Where the tooth starts in the arc
    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;
    double innerRadius = radius - ToothDepth;

    for (int t = 0; t < numTeeth; t++)
    {
        double angle1 = double(t) / double(numTeeth) * PI2;
        double angle2 = double(t + toothStart) / double(numTeeth) * PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(numTeeth) * PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(numTeeth) * PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(numTeeth) * PI2;

        AddPoint(innerRadius * cos(angle1), innerRadius * sin(angle1));
        AddPoint(innerRadius * cos(angle2), innerRadius * sin(angle2));
        AddPoint(radius * cos(angle3), radius * sin(angle3));
        AddPoint(radius * cos(angle4), radius * sin(angle4));
        AddPoint(innerRadius * cos(angle5), innerRadius * sin(angle5));
    }
}

/**
 * Draws the gear of the machine
 * @param graphics graphics to draw on
 * @param x x position
 * @param y y position
 */
void Gear::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x, y);
}
/**
 * Sets the rotation of the gear
 * @param rotation the rotation of our gear
 */
void Gear::SetRotation(double rotation)
{
    Component::SetRotation((rotation + mAdjust));
    mRotationSource.RotationSinking(-rotation);
}

/**
 * Drives the other gear that is attached to this gear
 * @param gear the driven gear
 * @param adjust the adjusting factor
 */
void Gear::Drive(std::shared_ptr<Gear> gear, double adjust)
{
    mAdjust = adjust;
    mRotationSource.AddRotationSink(gear->GetSink());
    this->SetRotation((this->GetRotation() + mAdjust));
}