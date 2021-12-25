/**
 * @file RotationSink.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"
#include "RotationSink.h"
#include "Component.h"

/**
 * Constructor
 */
RotationSink::RotationSink()
{

}

/**
 * Rotate the component
 * @param rotation amount of rotation
 */
void RotationSink::Rotate(double rotation)
{
    mComponent->SetRotation(rotation);
}

