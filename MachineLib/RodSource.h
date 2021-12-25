/**
 * @file RodSource.h
 * @author Rajaditya Shrikishan Bajaj
 *
 * The rod source for the negotiator
 */

#ifndef CANADIANEXPERIENCE_RODSOURCE_H
#define CANADIANEXPERIENCE_RODSOURCE_H

class RodSink;
class Rod;

/**
 * The rod source negotiator
 */
class RodSource {
private:
    /// List of sink objects to sink from source
    std::vector<RodSink*> mSinks;

public:

    RodSource();

    /// Destructor
    virtual ~RodSource() {}

    /// Copy constructor (disabled)
    RodSource(const RodSource&) = delete;

    /// Assignment operator (disabled)
    void operator=(const RodSource&) = delete;

    /**
     * Add the rotation sink to the source
     * @param positionSink rotation sink to be added
     */
    void AddRodSink(RodSink* positionSink)
    {
        mSinks.push_back(positionSink);
    };

    void RodNegotiating(Rod *rod);
};

#endif //CANADIANEXPERIENCE_RODSOURCE_H
