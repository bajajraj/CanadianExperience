/**
 * @file MachineFactory1.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * The factory class for the first machine
 */

#ifndef CANADIANEXPERIENCE_MACHINEFACTORY1_H
#define CANADIANEXPERIENCE_MACHINEFACTORY1_H

class ActualMachine;

/**
 * The first machine class
 */
class MachineFactory1 {
private:
    /// The images directory
    std::wstring mImagesDir;

public:
    MachineFactory1(std::wstring imagesDir);

    std::shared_ptr<ActualMachine> CreateMachine1();
};

#endif //CANADIANEXPERIENCE_MACHINEFACTORY1_H
