/**
 * @file RodSink.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"
#include "RodSink.h"
#include "Component.h"
#include "INegotiator.h"

/**
 * Constructor
 * @param component Component we are connected to.
 * @param negotiator The negotiator we will negotiate with
 */
RodSink::RodSink(Component *component, INegotiator *negotiator) :
        mComponent(component), mNegotiator(negotiator)
{
}

/**
 * Negotiator for the rod sink
 * @param rod the rod attached
 */
void RodSink::Negotiate(Rod *rod)
{
    mNegotiator->Negotiate(rod);
}