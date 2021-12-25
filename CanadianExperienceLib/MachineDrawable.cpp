/**
 * @file MachineDrawable.cpp
 * @author User
 */

#include "pch.h"
#include <machine-api.h>
#include <string>
#include "MachineDrawable.h"
#include "MainFrame.h"
#include "Timeline.h"

using namespace std;
/**
 * Constructor
 * @param name name of the machine
 * @param num machine number
 * @param imagesDir images directory
 */
MachineDrawable::MachineDrawable (const std::wstring& name, int num, const std::wstring imagesDir) :
        Drawable(name)
{
    mMachineNumber = num;
    MachineFactory factory(imagesDir);
    mMachine = factory.CreateMachine();

    mMachine->SetMachineNumber(num);
}

/**
 * Sets the frame of the machine
 * @param frame frame
 */
void MachineDrawable::SetFrame(int frame)
{
    mMachine->SetMachineFrame(frame);
}

/**
 * Sets the timeline for the machine drawable
 * @param timeline the timeline for the program
 */
void MachineDrawable::SetTimeline(Timeline* timeline)
{
    Drawable::SetTimeline(timeline);
    mTimeline = timeline;
}

/**
 * Draws the machine
 * @param graphics graphics to draw on
 */
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    // start frame and play button
    int frame = mTimeline->GetCurrentFrame();
    if (frame >= mStart)
    {
        mMachine->SetFrameRate(mTimeline->GetFrameRate());
        mMachine->SetMachineFrame(frame - mStart);
    }

    // the scale factor
    double scale = 0.30f;

    graphics->PushState();
    graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
    graphics->Scale(scale, scale);
    mMachine->SetLocation(wxPoint(0, 0));
    mMachine->DrawMachine(graphics);
    graphics->PopState();
}

/**
 * HitTest for the machine
 * @param pos position of the machine
 * @return false because we do not want to move the machine
 */
bool MachineDrawable::HitTest(wxPoint pos)
{
    return false;
}

/**
 * The dialog box function of the machine
 * @param parent the windows parent
 */
void MachineDrawable::ShowDialogBox(wxWindow *parent)
{
    MachineDialog dlg(parent, mMachine);
    if (dlg.ShowModal() == wxID_OK)
    {
        // A machine has been selected
    }
}