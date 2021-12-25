/**
 * @file MachineDerived.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * The derived machine we will work with
 */

#ifndef CANADIANEXPERIENCE_MACHINEDERIVED_H
#define CANADIANEXPERIENCE_MACHINEDERIVED_H

#include "Machine.h"
#include <vector>
#include <string>
#include <memory>
#include "Component.h"
#include "ActualMachine.h"

/**
 * The derive machine we will have
 */
class MachineDerived : public Machine {
private:
    /// Current Time
    double mTime = 0.0;

    ///Current Machine number
    int mMachineNumber = 1;

    /// Current Machine Number
    std::shared_ptr <ActualMachine> mActualMachine = nullptr;

    /// the image directory of the machine
    std::wstring mImagesDir;

    /// the machine speed
    double mMachineSpeed;

    /// The frame rate
    double mFrameRate = 30;

    /// The machine's location
    wxPoint mPosition = wxPoint(0,0);

public:
    MachineDerived(std::wstring imagesDir);

    /// Destructor
    ~MachineDerived() override {}

    /// Copy constructor/disabled
    MachineDerived(const MachineDerived&) = delete;

    /// Assignment operator/disabled
    void operator=(const MachineDerived&) = delete;

    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

     void SetMachineFrame(int frame) override;

     void SetMachineNumber(int machineNumber) override;

     int GetMachineNumber() override;

    /**
     * Sets the speed of the machine
     * @param speed the machine speed
     */
    void SetSpeed(double speed) override
    {
        mMachineSpeed = speed;
        mActualMachine->SetSpeed(speed);
    }

    /**
     * Getter for the machine time
     * @return the machine time
     */
    double GetMachineTime() override
    {
        return mTime;
    }

    /**
     * Setter for the frame rate
     * @param frameRate the frame rate
     */
    void SetFrameRate(double frameRate) override
    {
        mFrameRate = frameRate;
    }

    /**
     * Setter for the location
     * @param position the position of the machine
     */
    void SetLocation(wxPoint position)
    {
        mPosition = position;
    }

};

#endif //CANADIANEXPERIENCE_MACHINEDERIVED_H
