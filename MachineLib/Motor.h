/**
 * @file Motor.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * the class that is responsible for our motor
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H

#include <string>
#include "Component.h"
#include "Polygon.h"
#include "RotationSource.h"

/**
 * motor class
 */
class Motor : public Component {
private:
    /// Shaft for motor
    Polygon mShaft;

    /// the image directory
    std::wstring mImagesDir;

    /// the motor speed
    double mMotorSpeed;

    /// Rotation source for this component
    RotationSource mSource;
public:

    Motor(std::wstring imagesDir);

    /// Destructor
    virtual ~Motor() {}

    /// Copy constructor/disabled
    Motor(const Motor&) = delete;

    /// Assignment operator/disabled
    void operator=(const Motor&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override ;

    void Update(double time) override;

    /**
     * Sets the speed of the machine
     * @param speed the speed of the machine
     */
    void SetSpeed(double speed)
    {
        mMotorSpeed = speed;
    }

    /**
     * Getter for the source in component, i.e., motor in our machine
     * @return the source, i.e., the motor
     */
    RotationSource* GetSource()
    {
        return &mSource;
    }
};

#endif //CANADIANEXPERIENCE_MOTOR_H
