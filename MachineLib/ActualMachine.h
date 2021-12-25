/**
 * @file ActualMachine.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * The actual machine we will work with
 */

#ifndef CANADIANEXPERIENCE_ACTUALMACHINE_H
#define CANADIANEXPERIENCE_ACTUALMACHINE_H

#include <vector>
#include "Component.h"

class MachineDerived;

/**
 * The actual machine with which we will work
 */
class ActualMachine {
private:
    /// The time of the machine
    double mTime = 0.0;

    /// list of components
    std::vector<std::shared_ptr<Component>> mComponents;

    /// Machine Actual object
    MachineDerived* mDerivedMachine = nullptr;

public:
    ActualMachine() ;

    /**
    Destructor
    */
    virtual ~ActualMachine() {};

    /// Copy constructor/disabled
    ActualMachine(const ActualMachine&) = delete;

    /// Assignment operator/disabled
    void operator=(const ActualMachine&) = delete;

    void AddComponent(const std::shared_ptr<Component>& component);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) ;

    /**
     * Sets the actual machine
     * @param machineDerived the machine derived
     */
    void SetMachineActual(MachineDerived *machineDerived)
    {
        mDerivedMachine = machineDerived;
    }

    void SetTime(double time);

    void SetSpeed(double speed);
};

#endif //CANADIANEXPERIENCE_ACTUALMACHINE_H
