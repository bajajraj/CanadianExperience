/**
 * @file MachineFactory1.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"

#include "MachineFactory1.h"
#include "ActualMachine.h"
#include "Component.h"
#include "Motor.h"
#include "Gear.h"
#include "Arm.h"
#include "Rod.h"
#include "Piston.h"
#include "Lever.h"
#include "Shape.h"

using namespace std;

/**
 * Constructor
 * @param imagesDir Directory to load images from
 */
MachineFactory1::MachineFactory1(std::wstring imagesDir) : mImagesDir(imagesDir)
{
}


/**
 * Create a machine object
 *
 * Do not change the return type of this function!
 *
 * @return Object of type Machine
 */
std::shared_ptr<ActualMachine> MachineFactory1::CreateMachine1()
{
    auto machine = make_shared<ActualMachine>();

    // the base
    auto base = make_shared<Shape>();
    int wid = 550;
    base->Rectangle(-wid/2, -1, wid, 40);
    base->SetImage(mImagesDir + L"/base.png");
    machine->AddComponent(base);

    // The motor
    auto motor = make_shared<Motor>(mImagesDir);
    motor->SetPosition(wxPoint(100,-38));
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);

    // The gear driven by the motor
    // Radius=20pixels, 10 teeth
    auto gear1 = make_shared<Gear>(20, 10);
    gear1->SetImage(mImagesDir + L"/iron.png");
    gear1->SetPosition(wxPoint(100, -88));
    machine->AddComponent(gear1);

    motor->GetSource()->AddRotationSink(gear1->GetSink());

    // A post that holds the larger gear
    auto gear2post = make_shared<Component>();
    gear2post->Rectangle(-10, 0, 20, 30);
    gear2post->SetPosition(wxPoint(155, -40));
    gear2post->SetColor(wxColour(0, 128, 0));
    machine->AddComponent(gear2post);

    // The second gear
    // Radius=40pixels, 20 teeth
    auto gear2 = make_shared<Gear>(40, 20);
    gear2->SetImage(mImagesDir + L"/hammered-copper.png");
    gear2->SetPosition(wxPoint(155,-88));
    machine->AddComponent(gear2);

    gear1->Drive(gear2,0.1);

    // The arm attached to the second gear
    // 50 pixels long
    auto arm = make_shared<Arm>(50);
    arm->SetImage(mImagesDir + L"/arm1.png");
    arm->SetPosition(gear2->GetPosition());
    machine->AddComponent(arm);

    gear2->GetSource()->AddRotationSink(arm->GetSink());

    // The column that holds the lever
    auto column = make_shared<Shape>();
    column->Rectangle(-20, -40, 40, 220);
    column->SetImage(mImagesDir + L"/column.png");

    // The lever
    auto lever = make_shared<Lever>(400);
    lever->SetPosition(wxPoint(0, -232));
    lever->SetImage(mImagesDir + L"/lever.png");
    lever->SetDriveLength(185);
    machine->AddComponent(lever);

    // The flag attached to the lever
    // Adding the points allows (0,0) be at the end
    // of the flagpole, so it rotates around that point.
    auto flag = make_shared<Shape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(mImagesDir + L"/flag.png");
    flag->SetPosition(lever->GetPosition());
    machine->AddComponent(flag);
    lever->GetRotationSource()->AddRotationSink(flag->GetSink());

    // Column is added after the lever so it is in front
    machine->AddComponent(column);

    // Rod from arm to lever
    // 150 pixels long, 7 pixels wide
    auto rod1 = make_shared<Rod>(150,7);
    int gray = 50;
    rod1->SetColor(wxColour(gray, gray, gray));
    machine->AddComponent(rod1);

    rod1->GetRodSource()->AddRodSink(lever->GetRodSink());

    arm->GetPositionSource()->AddComponent(rod1);

    // Rod from lever to Piston
    // 50 pixels long, 5 pixels wide
    auto rod2 = make_shared<Rod>(50, 5);
    rod2->SetColor(wxColour(gray, gray, gray));
    machine->AddComponent(rod2);

    lever->GetPositionSource()->AddComponent(rod2);

    // Piston
    // The points are added so that (0,0) is
    // the attachment point for the rod.
    auto piston = make_shared<Piston>();
    double pistonH = 90;
    double pistonW = 0.386 * pistonH;
    double pistonC = 13.0 / 215.0 * pistonH;
    piston->AddPoint(-pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC + pistonH);
    piston->AddPoint(-pistonW / 2, -pistonC + pistonH);
    piston->SetImage(mImagesDir + L"/piston.png");
    piston->SetPosition(wxPoint(-175, -150));
    machine->AddComponent(piston);

    rod2->GetRodSource()->AddRodSink(piston->GetRodSink());


    // Cylinder
    auto cylinder = make_shared<Shape>();
    cylinder->Rectangle(-30, 0, 60, 120);
    cylinder->SetPosition(wxPoint(-175, -38));
    cylinder->SetImage(mImagesDir + L"/cylinder.png");
    machine->AddComponent(cylinder);

    return machine;
}



