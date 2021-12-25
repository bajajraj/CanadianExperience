/**
 * @file PositionSource.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"
#include "PositionSource.h"
#include "Component.h"
#include "PositionSink.h"

/**
 * Function that updates all the position of the sink attached
 * @param position the position of the component
 */
void PositionSource::SetPositions(wxPoint position)
{
    for (auto sink : mSinks)
    {
        // Setting the position of the sink
        sink->SetPosition(position);
    }
}