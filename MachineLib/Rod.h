/**
 * @file Rod.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * Component class for the rod
 */

#ifndef CANADIANEXPERIENCE_ROD_H
#define CANADIANEXPERIENCE_ROD_H

#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"
#include "RodSink.h"
#include "RodSource.h"

/**
 * Rod component class
 */
class Rod : public Component {
private:
    /// The length of the rod
    int mRodLength;

    /// The width of the rod
    int mRodWidth;

    /// The rotation sink of the rod
    RotationSink mSink;

    /// Rotation source for this component
    RotationSource mSource;

    /// Rod source for the rod
    RodSource mRodSource;

public:
    Rod(int rodLength, int rodWidth);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics,int x, int y) override;

    /**
     * Getter for the rotation sink
     * @return the rotation sink
     */
    RotationSink* GetSink()
    {
        return &mSink;
    }

    /**
     * Getter for the rotation source
     * @return the rotation source
     */
    RotationSource* GetSource()
    {
        return &mSource;
    }

    void Update(double time) override;

    /**
     * Getter for the rod length
     * @return the rod length
     */
    int GetRodLength() const
    {
        return mRodLength;
    }

    /**
     * Getter for the rod source
     * @return the rod source
     */
    RodSource* GetRodSource()
    {
        return &mRodSource;
    }
};

#endif //CANADIANEXPERIENCE_ROD_H
