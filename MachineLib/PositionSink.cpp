/**
 * @file PositionSink.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"
#include "PositionSink.h"
#include "Component.h"

/**
 * Sets the position of the sink
 * @param position the given position
 */
void PositionSink::SetPosition(wxPoint position)
{
    mComponent->SetPosition(position);
}
