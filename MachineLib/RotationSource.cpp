/**
 * @file RotationSource.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"
#include "RotationSource.h"
#include "Component.h"

/**
 * Constructor
 */
RotationSource::RotationSource()
{
}

/**
 * Sink the rotation
 * @param rotation the amount of rotation
 */
void RotationSource::RotationSinking(double rotation)
{
    for (auto sink : mSinks)
    {
        sink->Rotate(rotation);
    }
}

