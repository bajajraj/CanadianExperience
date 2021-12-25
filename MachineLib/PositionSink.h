/**
 * @file PositionSink.h
 * @author User
 *
 * class that handles the position sink for the component
 */

#ifndef CANADIANEXPERIENCE_POSITIONSINK_H
#define CANADIANEXPERIENCE_POSITIONSINK_H

class Component;

/**
 * Position sink handling class
 */
class PositionSink {
private:
    /// Component to sink
    Component* mComponent;

public:
    PositionSink() {};

    /// Destructor
    virtual ~PositionSink() {};

    /// Copy constructor (disabled)
    PositionSink(const PositionSink&) = delete;

    /// Assignment operator (disabled)
    void operator=(const PositionSink&) = delete;

    /**
     * Sets the component in the sink
     * @param component the component we will have
     */
    void SetPositionComponent(Component* component)
    {
        mComponent = component;
    }

    /**
     * Getter for the sink component
     * @return component
     */
    Component* GetPositionComponent()
    {
        return mComponent;
    }

    void SetPosition(wxPoint position);

};

#endif //CANADIANEXPERIENCE_POSITIONSINK_H
