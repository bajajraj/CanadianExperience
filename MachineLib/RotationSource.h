/**
 * @file RotationSource.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * Class that handles the rotation source
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONSOURCE_H

#include <vector>
#include "RotationSink.h"

/**
 * Rotation source class
 */
class RotationSource {
private:
    /// List of sink objects to sink from source
    std::vector<RotationSink*> mSinks;
public:
    RotationSource();

    /// Destructor
    virtual ~RotationSource() {}

    /// Copy constructor (disabled)
    RotationSource(const RotationSource&) = delete;

    /// Assignment operator (disabled)
    void operator=(const RotationSource&) = delete;

    /**
     * Add the rotation sink to the source
     * @param rotationSink rotation sink to be added
     */
    void AddRotationSink(RotationSink* rotationSink)
    {
        mSinks.push_back(rotationSink);
    };

    void RotationSinking(double rotation);
};

#endif //CANADIANEXPERIENCE_ROTATIONSOURCE_H
