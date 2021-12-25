/**
 * @file Gear.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * The class for gear in the machine
 */

#ifndef CANADIANEXPERIENCE_GEAR_H
#define CANADIANEXPERIENCE_GEAR_H
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"

/**
 * Gear component class
 */
class Gear : public Component{
private:
    ///teeth of gear
    int mTeeth = 10;

    ///Adjust constant
    double mAdjust = 0.0;

    /// The rotation sink for this component
    RotationSink mRotationSink;

    /// Rotation source for this component
    RotationSource mRotationSource;
public:

    Gear(int radius, int teeth);

    /// Destructor
    ~Gear() override {}

    /// Copy constructor/disabled
    Gear(const Gear&) = delete;

    /// Assignment operator/disabled
    void operator=(const Gear&) = delete;

    /**
     * Getter for the sink
     * @return the sink attached
     */
    RotationSink* GetSink()
    {
        return &mRotationSink;
    }

    void SetRotation(double rotation) override;

    void Drive(std::shared_ptr<Gear> gear, double adjust);

    /**
     * Getter for our source
     * @return the source
     */
    RotationSource* GetSource()
    {
        return &mRotationSource;
    }

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;
};

#endif //CANADIANEXPERIENCE_GEAR_H
