/**
 * @file Arm.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"

#include <cmath>
#include "Arm.h"
#include "Component.h"
#include "Polygon.h"
#include "RotationSource.h"
#include "RotationSink.h"
#include "PositionSink.h"

/// M_PI * 2 value
double PI2 = M_PI * 2;

/**
 * Constructor
 * @param armLength the length of the arm
 */
Arm::Arm(int armLength) : mArmLength(armLength)
{
    // Setting the sink component
    mSink.SetComponent(this);
    Rectangle(-5, 5, mArmLength, int(0.25*mArmLength));
}

/**
 * Draws the arm
 * @param graphics the graphics to draw on
 * @param x x position
 * @param y y position
 */
void Arm::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x, y);

    wxPoint rodPosition = RodPosition();
    mSource.SetPositions(rodPosition);
}

/**
 * Updates the component
 * @param time the current time
 */
void Arm::Update(double time)
{
    double rotation = - time * GetMachineSpeed();
    SetRotation(rotation);

    wxPoint rodPosition = RodPosition();
    mSource.SetPositions(rodPosition);
}

/**
 * Function to find the position of the rod attached
 * @return position of the rod
 */
wxPoint Arm::RodPosition()
{
    // Rod position attached
    double x = GetPosition().x + (mArmLength - 14) * cos(GetRotation() * PI2);
    double y = GetPosition().y + (mArmLength - 9) * sin(GetRotation() * PI2);

    return wxPoint(int(x), int(y));
}