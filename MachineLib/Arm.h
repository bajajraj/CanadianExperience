/**
 * @file Arm.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * Class that handles the arm
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H

#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"
#include "PositionSource.h"

/**
 * Arm component class
 */
class Arm : public Component{
private:

    /// The arm's length
    int mArmLength;

    /// The rotation sink for the component
    RotationSink mSink;

    /// Rotation source for this component
    PositionSource mSource;
public:
    Arm(int armLength);

    /// Destructor
    ~Arm() override {}

    /// Copy constructor/disabled
    Arm(const Arm&) = delete;

    /// Assignment operator/disabled
    void operator=(const Arm&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int , int y) override;

    void Update(double time) override;

    /**
     * Getter for the rotation sink
     * @return the rotation sink
     */
    RotationSink* GetSink()
    {
        return &mSink;
    }

    /**
     * Getter for the position source
     * @return the position source
     */
    PositionSource* GetPositionSource()
    {
        return &mSource;
    }

    wxPoint RodPosition();
};

#endif //CANADIANEXPERIENCE_ARM_H
