/**
 * @file MachineDrawable.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * Drawable class for the machine
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLE_H

#include <machine-api.h>
#include <string>
#include "Drawable.h"

class Timeline;

/**
 * Drawable class for the machine
 */
class MachineDrawable : public Drawable{
private:
    ///Machine associated with this adapter class
    std::shared_ptr<Machine> mMachine;

    /// Start frame for machine drawable
    int mStart = 0;

    /// The timeline associated
    Timeline *mTimeline = nullptr;

    /// The image directory
    std::wstring mImagesDir;

    /// The machine number
    int mMachineNumber = 1;

public:
    MachineDrawable(const std::wstring& name, int num, const std::wstring imagesDir);

    ~MachineDrawable() override {}

    /** Default constructor disabled */
    MachineDrawable() = delete;

    /** Copy constructor disabled */
    MachineDrawable(const MachineDrawable&) = delete;

    /** Assignment operator disabled */
    void operator=(const MachineDrawable&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void ShowDialogBox(wxWindow *parent);

    bool HitTest(wxPoint pos) override;

    void SetTimeline(Timeline* timeline) override;

    void SetFrame(int frame);

    /**
     * Getter for the starting frame
     * @return the start frame
     */
    int GetStart() const
    {
        return mStart;
    }

    /**
     * Setter for start frame
     * @param start start frame
     */
    void SetStart(int start)
    {
        mStart = start;
    }

    /**
     * Setter for machine number
     * @param num the machine number
     */
    void SetMachineNumber(int num)
    {
        mMachineNumber = num;
    }

    /**
     * Getter for machine number
     * @return the machine number
     */
    int GetMachineNumber() const
    {
        return mMachineNumber;
    }
};

#endif //CANADIANEXPERIENCE_MACHINEDRAWABLE_H
