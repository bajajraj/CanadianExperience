/**
 * @file Picture.h
 *
 * @author Charles B. Owen
 *
 *  Class that represents our animation picture
 */

#pragma once

#include "Timeline.h"

class PictureObserver;
class Actor;
class MachineDrawable;

/**
 *  Class that represents our animation picture
 */
class Picture
{
private:
    /// The picture size
    wxSize mSize = wxSize(1500, 800);

    /// The observers of this picture
    std::vector<PictureObserver *> mObservers;

    /// The actors associated with this picture
    std::vector<std::shared_ptr<Actor>> mActors;

    /// The animation timeline
    Timeline mTimeline;

    ///Machine drawable 1 associated
    std::shared_ptr<MachineDrawable> mMachine1 = nullptr;

    ///Machine drawable 2 associated
    std::shared_ptr<MachineDrawable> mMachine2 = nullptr;

public:
    Picture();

    /// Copy Constructor (Disabled)
    Picture(const Picture &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Picture &) = delete;

    /**
     * Destructor
    */
    virtual ~Picture() = default;

    /**
     * Get the picture size
     * @return Picture size in pixels
     */
    wxSize GetSize() {return mSize;}

    /**
     * Set the picture size
     * @param size Picture size in pixels
     */
    void SetSize(wxSize size) {mSize = size;}

    /**
     * Get a pointer to the Timeline object
     * @return Pointer to the Timeline object
     */
    Timeline *GetTimeline() {return &mTimeline;}

    void AddObserver(PictureObserver *observer);
    void RemoveObserver(PictureObserver *observer);
    void UpdateObservers();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void AddActor(std::shared_ptr<Actor> actor);

    /** Iterator that iterates over the actors in a picture */
    class ActorIter
    {
    public:
        /**
         * Constructor
         * @param picture Picture we are iterating
         * @param pos Starting position \
         */
        ActorIter(Picture *picture, int pos) : mPicture(picture), mPos(pos) {}

        /**
         * Test for end of the iterator
         * @param other Other object to test against
         * @return True if we this position equals not equal to the other position
         */
        bool operator!=(const ActorIter &other) const
        {
            return mPos != other.mPos;
        }

        /**
         * Get value at current position
         * @return Value at mPos in the collection
         */
        std::shared_ptr<Actor> operator *() const { return mPicture->mActors[mPos]; }

        /** Increment the iterator
        * @return Reference to this iterator */
        const ActorIter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        Picture *mPicture;  ///< Picture we are iterating over
        int mPos;           ///< Position in the collection
    };

    /**
     * Get an iterator for the beginning of the collection
     * @return Iter object at position 0
     */
    ActorIter begin() { return ActorIter(this, 0); }

    /**
     * Get an iterator for the end of the collection
     * @return Iter object at position past the end
     */
    ActorIter end() { return ActorIter(this, mActors.size()); }

    void SetAnimationTime(double time);

    double GetAnimationTime();

    void Load(const wxString& filename);

    void Save(const wxString& filename);

    /**
     * Setter for machine 1
     * @param machine1 the machine 1
     */
    void SetMachine1(std::shared_ptr<MachineDrawable> machine1)
    {
        mMachine1 = machine1;
    }

    /**
     * Setter for machine 2
     * @param machine2 the machine 2
     */
    void SetMachine2(std::shared_ptr<MachineDrawable> machine2)
    {
        mMachine2 = machine2;
    }

    void Machine1DialogBox(wxWindow* parent);

    void Machine2DialogBox(wxWindow* parent);
};

