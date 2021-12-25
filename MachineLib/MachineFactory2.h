/**
 * @file MachineFactory2.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * The factory class for machine 2
 */

#ifndef CANADIANEXPERIENCE_MACHINEFACTORY2_H
#define CANADIANEXPERIENCE_MACHINEFACTORY2_H

class ActualMachine;

/**
 * The second machine factory class
 */
class MachineFactory2 {
private:
    /// The images directory
    std::wstring mImagesDir;

public:
    MachineFactory2(std::wstring imagesDir);

    std::shared_ptr<ActualMachine> CreateMachine2();
};

#endif //CANADIANEXPERIENCE_MACHINEFACTORY2_H
