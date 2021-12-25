/**
 * @file MachineDerived.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"

#include <string>

#include "MachineDerived.h"
#include "Polygon.h"
#include "MachineFactory.h"
#include "MachineFactory1.h"
#include "MachineFactory2.h"

using namespace std;

/**
 * Constructor
 * @param imagesDir the image directory
 */
MachineDerived::MachineDerived(std::wstring imagesDir) : mImagesDir(imagesDir)
{
    // Setting the default machine number
    SetMachineNumber(1);

}

/**
 * Draws the machine
 * @param graphics the graphics to draw on
 */
void MachineDerived::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mActualMachine->Draw(graphics, mPosition.x, mPosition.y);
}

/**
 * Sets the machine frame
 * @param frame the given frame
 */
void MachineDerived::SetMachineFrame(int frame)
{
    mTime = frame / mFrameRate;
    mActualMachine->SetTime(mTime);
}

/**
 * Sets the machine as required
 * @param machineNumber the machine number
 */
void MachineDerived::SetMachineNumber(int machineNumber)
{
    // If machine number is not 2
    if (machineNumber != 2) {
        mMachineNumber = 1;
        MachineFactory1 factory1(mImagesDir);

        mActualMachine = factory1.CreateMachine1();

        mActualMachine->SetMachineActual(this);
    }
    // if machine number is 2
    else
    {
        mMachineNumber = 2;

        MachineFactory2 factory2(mImagesDir);

        mActualMachine = factory2.CreateMachine2();

        mActualMachine->SetMachineActual(this);
    }

}

/**
 * Getter for the machine number
 * @return the machine number
 */
int MachineDerived::GetMachineNumber()
{
    return mMachineNumber;
}


