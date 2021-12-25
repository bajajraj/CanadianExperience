/**
 * @file Component.h
 * @author User
 *
 * Base class for the components of the machine
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

#include "Polygon.h"

class ActualMachine;
class MachineDerived;

/**
 * Base class for the components of the machine
 */
class Component : public Polygon{
private:
    /// Position of the machine
    wxPoint mPosition = wxPoint(0, 0);

    /// current frame
    int mCurrentFrame = 0;

    /// Current time
    double mTime = 0.0;

    ///Working machine
    ActualMachine* mActualMachine;

    /// the speed of the machine
    double mMachineSpeed = 1;

public:
    Component();

    /// Destructor
    ~Component() override {}

    /// Copy constructor/disabled
    Component(const Component&) = delete;

    /// Assignment operator/disabled
    void operator=(const Component&) = delete;

    /**
     * Sets the position of the component
     * @param point the position
     */
    virtual void SetPosition(wxPoint point)
    {
        mPosition = point;
    }

    /**
     * Gets the position of the component
     * @return the position of the component
     */
    wxPoint GetPosition() { return mPosition; }

    virtual void Update(double time);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /**
     * Sets the machine this component is associated with
     * @param actualMachine the associated machine
     */
    void SetMachine(ActualMachine* actualMachine)
    {
        mActualMachine = actualMachine;
    }

    /**
     * Getter for the time
     * @return the time
     */
    double GetTime() const
    {
        return mTime;
    }

    /**
     * Setter for the machine speed
     * @param speed
     */
    virtual void SetMachineSpeed(double speed)
    {
        mMachineSpeed = speed;
    }

    /**
     * Getter for the machine speed
     * @return the machine speed
     */
    virtual double GetMachineSpeed() const
    {
        return mMachineSpeed;
    }
};

#endif //CANADIANEXPERIENCE_COMPONENT_H
