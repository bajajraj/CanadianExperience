/**
 * @file RodSink.h
 * @author User
 *
 * The rod sink to the rod for lever and piston
 */

#ifndef CANADIANEXPERIENCE_RODSINK_H
#define CANADIANEXPERIENCE_RODSINK_H

class Component;
class Rod;
class INegotiator;

/**
 * Negotiator for the rod sink
 */
class RodSink {
private:
    /// The component attached to the rod
    Component *mComponent;

    /// The negotiator for the rod
    INegotiator *mNegotiator;

public:
    RodSink(Component *component, INegotiator *negotiator);

    /// Destructor
    virtual ~RodSink() {}

    /// Copy constructor (disabled)
    RodSink(const RodSink&) = delete;

    /// Assignment operator (disabled)
    void operator=(const RodSink&) = delete;

    void Negotiate(Rod* rod);
};

#endif //CANADIANEXPERIENCE_RODSINK_H
