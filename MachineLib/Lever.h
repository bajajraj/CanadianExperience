/**
 * @file Lever.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * Component class for lever in the machine
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"
#include "RotationSource.h"
#include "PositionSource.h"
#include "RotationSink.h"
#include "INegotiator.h"
#include "Rod.h"

class RodSink;

/**
 * Lever component class
 */
class Lever : public Component, public INegotiator {
private:

    /// The length of the lever
    int mLeverLength;

    /// Rotation source for this component
    RotationSource mRotationSource;

    /// Rotation source for this component
    PositionSource mPositionSource;

    /// The rod sink for the lever
    RodSink mRodSink;

    /// The drive length of the lever
    double mDriveLength;

public:

    Lever(int leverLength);

    /// Destructor
    virtual ~Lever() {}

    /// Copy constructor/disabled
    Lever(const Lever&) = delete;

    /// Assignment operator/disabled
    void operator=(const Lever&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    /**
    * Getter for the source in component,
    * @return the source,
    */
    RotationSource* GetRotationSource()
    {
        return &mRotationSource;
    }

    /**
     * Getter for the position source in the component
     * @return the position source
     */
    PositionSource* GetPositionSource() { return &mPositionSource; }

    void Negotiate(Rod* rod) override;

    /**
     * Getter for the rod sink
     * @return the rod sink
     */
    RodSink* GetRodSink()
    {
        return &mRodSink;
    }

    void Update(double time) override;

    /**
     * Setter for the drive length
     * @param driveLength the drive length
     */
    void SetDriveLength(int driveLength)
    {
        mDriveLength = driveLength;
    }
};

#endif //CANADIANEXPERIENCE_LEVER_H
