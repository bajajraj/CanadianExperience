/**
 * @file Shape.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * The basic shape class
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H

#include "Component.h"
#include "RotationSink.h"

/**
 * The basic shape class
 */
class Shape : public Component{
private:
    /// The rotation sink for the component
    RotationSink mSink;
public:

    Shape();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    void Update(double time) override;

    /**
     * Getter for the rotation sink
     * @return the rotation sink
     */
    RotationSink* GetSink()
    {
        return &mSink;
    }
};

#endif //CANADIANEXPERIENCE_SHAPE_H
