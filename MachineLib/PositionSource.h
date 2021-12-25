/**
 * @file PositionSource.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * Class that handles the component's position source
 */

#ifndef CANADIANEXPERIENCE_POSITIONSOURCE_H
#define CANADIANEXPERIENCE_POSITIONSOURCE_H

#include "PositionSink.h"
#include <vector>

class Component;

/**
 * Position source class
 */
class PositionSource {
private:
    /// List of sink objects to sink from source
    std::vector<std::shared_ptr<Component>> mSinks;
public:
    PositionSource() {};

    /// Destructor
    virtual ~PositionSource() {}

    /// Copy constructor (disabled)
    PositionSource(const PositionSource&) = delete;

    /// Assignment operator (disabled)
    void operator=(const PositionSource&) = delete;

    /**
     * Add the rotation sink to the source
     * @param positionSink rotation sink to be added
     */
    void AddComponent(std::shared_ptr<Component> positionSink)
    {
        mSinks.push_back(positionSink);
    }

    void SetPositions(wxPoint position);
};

#endif //CANADIANEXPERIENCE_POSITIONSOURCE_H
