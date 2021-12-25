/**
 * @file MachineFactory2.cpp
 * @author Rajaditya Shrikishan Bajaj
 */

#include "pch.h"
#include "MachineFactory2.h"
#include "ActualMachine.h"
#include "Motor.h"
#include "Gear.h"
#include "Shape.h"
using namespace std;
/**
 * Constructor
 * @param imagesDir Directory to load images from
 */
MachineFactory2::MachineFactory2(std::wstring imagesDir) : mImagesDir(imagesDir)
{
}


/**
 * Create a machine object
 *
 * Do not change the return type of this function!
 *
 * @return Object of type Machine
 */
std::shared_ptr<ActualMachine> MachineFactory2::CreateMachine2()
{
    auto machine = make_shared<ActualMachine>();

    // the base //
    auto base = make_shared<Shape>();
    int wid = 550;
    base->Rectangle(-wid/2, -1, wid, 40);
    base->SetImage(mImagesDir + L"/rust.png");
    machine->AddComponent(base);

    // --------------------------------------------------------------- //
    // The wall on the sides //
    auto leftWall = make_shared<Shape>();
    int leftWallWid = 30;
    leftWall->Rectangle(-275,-370, leftWallWid,-370);
    leftWall->SetImage(mImagesDir + L"/rust.png");
    machine->AddComponent(leftWall);

    auto rightWall = make_shared<Shape>();
    int rightWallWid = 30;
    rightWall->Rectangle(250,-370,rightWallWid,-370);
    rightWall->SetImage(mImagesDir + L"/rust.png");
    machine->AddComponent(rightWall);

    // -----------------------------------------------------------------//
    // The flags attached to the wall //
    // The flag attached to the lever
    // Adding the points allows (0,0) be at the end
    // of the flagpole, so it rotates around that point.
    auto leftFlag = make_shared<Shape>();
    leftFlag->AddPoint(-50, 0);
    leftFlag->AddPoint(-50, -75);
    leftFlag->AddPoint(5, -75);
    leftFlag->AddPoint(5, 0);
    leftFlag->SetImage(mImagesDir + L"/msu-flag.png");
    leftFlag->SetPosition(wxPoint(-210,-370));
    machine->AddComponent(leftFlag);

    auto rightFlag = make_shared<Shape>();
    rightFlag->AddPoint(-50, 0);
    rightFlag->AddPoint(-50, -75);
    rightFlag->AddPoint(5, -75);
    rightFlag->AddPoint(5, 0);
    rightFlag->SetImage(mImagesDir + L"/msu-flag.png");
    rightFlag->SetPosition(wxPoint(312,-370));
    machine->AddComponent(rightFlag);

    // -----------------------------------------------------------------//
    // The motor //
    auto motor = make_shared<Motor>(mImagesDir);
    motor->SetPosition(wxPoint(0,-38));
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);

    // ----------------------------------------------------------------- //
    // The right side gears //

    // The gear driven by the motor
    // Radius=20pixels, 10 teeth
    auto gear1 = make_shared<Gear>(10, 10);
    gear1->SetImage(mImagesDir + L"/iron.png");
    gear1->SetPosition(wxPoint(0, -88));
    machine->AddComponent(gear1);

    motor->GetSource()->AddRotationSink(gear1->GetSink());

    // The second gear
    // Radius=40pixels, 20 teeth
    auto gear2 = make_shared<Gear>(20, 20);
    gear2->SetImage(mImagesDir + L"/hammered-copper.png");
    gear2->SetPosition(wxPoint(20,-88));
    machine->AddComponent(gear2);

    gear1->Drive(gear2,0.1);

    // The third gear
    // Radius=30pixels, 20 teeth
    auto gear3 = make_shared<Gear>(30, 20);
    gear3->SetImage(mImagesDir + L"/hammered-copper.png");
    gear3->SetPosition(wxPoint(55,-115));
    machine->AddComponent(gear3);

    gear2->Drive(gear3,0.15);

    // The fourth gear
    // Radius=40pixels, 25 teeth
    auto gear4 = make_shared<Gear>(40, 25);
    gear4->SetImage(mImagesDir + L"/hammered-copper.png");
    gear4->SetPosition(wxPoint(107,-150));
    machine->AddComponent(gear4);

    gear3->Drive(gear4,0.25);

    // The fifth gear
    // Radius=50pixels, 30 teeth
    auto gear5 = make_shared<Gear>(50, 30);
    gear5->SetImage(mImagesDir + L"/hammered-copper.png");
    gear5->SetPosition(wxPoint(177,-190));
    machine->AddComponent(gear5);

    gear4->Drive(gear5,0.4);

    //---------------------------------------------------------------------//

    // Left side gears //

    // The second gear
    // Radius=40pixels, 20 teeth
    auto lgear2 = make_shared<Gear>(20, 20);
    lgear2->SetImage(mImagesDir + L"/hammered-copper.png");
    lgear2->SetPosition(wxPoint(-20,-88));
    machine->AddComponent(lgear2);

    gear1->Drive(lgear2,0.1);

    // The second gear
    // Radius=40pixels, 20 teeth
    auto lgear3 = make_shared<Gear>(30, 20);
    lgear3->SetImage(mImagesDir + L"/hammered-copper.png");
    lgear3->SetPosition(wxPoint(-55,-115));
    machine->AddComponent(lgear3);

    lgear2->Drive(lgear3,0.15);

    // The second gear
    // Radius=40pixels, 20 teeth
    auto lgear4 = make_shared<Gear>(40, 25);
    lgear4->SetImage(mImagesDir + L"/hammered-copper.png");
    lgear4->SetPosition(wxPoint(-107,-150));
    machine->AddComponent(lgear4);

    lgear3->Drive(lgear4,0.25);

    // The second gear
    // Radius=40pixels, 20 teeth
    auto lgear5 = make_shared<Gear>(50, 30);
    lgear5->SetImage(mImagesDir + L"/hammered-copper.png");
    lgear5->SetPosition(wxPoint(-177,-190));
    machine->AddComponent(lgear5);

    lgear4->Drive(lgear5,0.4);

    return machine;
}
