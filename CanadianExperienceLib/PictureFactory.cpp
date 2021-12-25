/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"

using namespace std;

/**
 * Factory method to create a new picture.
 * @param imagesDir Directory that contains the images for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Picture> picture = make_shared<Picture>();


    // Create the background and add it
    auto background = make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            make_shared<ImageDrawable>(L"Background", imagesDir + L"/factory-background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 500));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 520));
    picture->AddActor(sparty);

    // Add machine 1 to canadian experience
    auto machineDrawable1 = make_shared<Actor>(L"Machine1 Drawable");
    machineDrawable1->SetPosition(wxPoint(850, 550));

    auto machine1 = make_shared<MachineDrawable>(L"Machine1", 1, imagesDir);
    machine1->SetStart(30);
    machineDrawable1->AddDrawable(machine1);
    machineDrawable1->SetRoot(machine1);

    picture->SetMachine1(machine1);
    picture->AddActor(machineDrawable1);

    // Add machine 2 to canadian experience
    auto machineDrawable2 = make_shared<Actor>(L"Machine 2 Drawable");
    machineDrawable2->SetPosition(wxPoint(850, 300));

    auto machine2 = make_shared<MachineDrawable>(L"Machine2", 2, imagesDir);
    machine2->SetStart(70);
    machineDrawable2->AddDrawable(machine2);
    machineDrawable2->SetRoot(machine2);

    picture->SetMachine2(machine2);
    picture->AddActor(machineDrawable2);

    return picture;
}

