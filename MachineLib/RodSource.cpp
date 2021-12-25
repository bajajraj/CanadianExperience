/**
 * @file RodSource.cpp
 * @author Rajaditya Shrikishan BAjaj
 */

#include "pch.h"
#include "RodSource.h"
#include "RodSink.h"
#include "Rod.h"

/**
 * Constructor
 */
RodSource::RodSource()
{
}

/**
 * Sink the negotiator
 * @param rod the rod attach
 */
void RodSource::RodNegotiating(Rod *rod)
{
    for (auto sink : mSinks)
    {
        sink->Negotiate(rod);
    }
}