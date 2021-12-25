/**
 * @file Piston.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * The class that handles the component piston
 */

#ifndef CANADIANEXPERIENCE_PISTON_H
#define CANADIANEXPERIENCE_PISTON_H

#include "Component.h"
#include "INegotiator.h"
#include "RotationSink.h"
#include "Rod.h"

class RodSink;

/**
 * Piston class
 */
class Piston : public Component, public INegotiator {
private:
    /// The rod sink for the lever
    RodSink mRodSink;

public:
    Piston();

    /// Destructor
    ~Piston() override {};

    /// Copy constructor/disabled
    Piston(const Piston&) = delete;

    /// Assignment operator/disabled
    void operator=(const Piston&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    /**
     * Getter for the rod sink
     * @return the rod sink
     */
    RodSink* GetRodSink()
    {
        return &mRodSink;
    }

    void Negotiate(Rod* rod) override;
};

#endif //CANADIANEXPERIENCE_PISTON_H
