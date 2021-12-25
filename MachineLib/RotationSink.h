/**
 * @file RotationSink.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * Class that handles the rotation sink
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSINK_H
#define CANADIANEXPERIENCE_ROTATIONSINK_H

class Component;

/**
 * Rotation sink class
 */
class RotationSink {
private:
    /// Component to sink
    Component* mComponent;
public:
    RotationSink();

    void Rotate(double rotation);

    /// Destructor
    virtual ~RotationSink() {}

    /// Copy constructor (disabled)
    RotationSink(const RotationSink&) = delete;

    /// Assignment operator (disabled)
    void operator=(const RotationSink&) = delete;

    /**
     * Sets the component in the sink
     * @param component the component we will have
     */
    void SetComponent(Component* component)
    {
        mComponent = component;
    }
};

#endif //CANADIANEXPERIENCE_ROTATIONSINK_H
