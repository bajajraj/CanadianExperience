/**
 * @file ActualMachine.cpp
 * @author Rajaditya Shrikishan Bajaja
 */

#include "pch.h"

#include <vector>
#include <memory>

#include "ActualMachine.h"
#include "MachineDerived.h"
#include "Component.h"

using namespace std;

/**
 * Constructor
 */
ActualMachine::ActualMachine()
{

}

/**
 * Adds the component to the machine
 * @param component the component to be added
 */
void ActualMachine::AddComponent(const std::shared_ptr<Component>& component)
{
    component->SetMachine(this);
    mComponents.push_back(component);
}

/**
 * Draws the component of the machine
 * @param graphics graphics to draw on
 * @param x x position
 * @param y y position
 */
void ActualMachine::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    for (auto component : mComponents)
    {
        component->Draw(graphics, x, y);
    }
}

/**
 * Sets the time of components in the machine
 * @param time the given time
 */
void ActualMachine::SetTime(double time)
{
    mTime = time;
    for (auto component : mComponents)
    {
       component->Update(time);
    }
}

/**
 * Sets the machine speed
 * @param speed the speed of the machine
 */
void ActualMachine::SetSpeed(double speed)
{
    // to rotate the machine while speed is increasing
    for (auto component : mComponents)
    {
        component->SetMachineSpeed(speed);
        component->Update(mTime);
    }
}
