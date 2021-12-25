/**
 * @file Motor.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"
#include <string>
#include "Motor.h"
#include "Polygon.h"

/**
 * Constructor
 * @param imagesDir the image directory
 */
Motor::Motor(std::wstring imagesDir) : mImagesDir(imagesDir)
{
    // The base of the motor
    Rectangle(-50,0 ,100 , 100);

    // Setting the image of the motor-frame
    SetImage(imagesDir + L"/motor-frame.png");

    // Size of the motor
    mShaft.CenteredSquare(50);

    // Set the shaft image
    mShaft.SetImage(imagesDir + L"/electric-wheel.png");
}

/**
 * Draws the motor of the machine
 * @param graphics graphics to draw on
 * @param x x position
 * @param y y position
 */
void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x , y);

    // Draw for the shaft on motor
    mShaft.DrawPolygon(graphics, x + GetPosition().x , y + GetPosition().y - 50);
}

/**
 * Updates the machine
 * @param time the current time
 */
void Motor::Update(double time)
{
    // The rotation for the motor
    double rotation = time * mMotorSpeed * GetMachineSpeed();

    // The shaft rotation
    mShaft.SetRotation(rotation);

    // The source rotation
    mSource.RotationSinking(rotation);
}
