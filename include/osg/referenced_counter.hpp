#ifndef OSG_DEBUG_HPP
#define OSG_DEBUG_HPP

namespace osg {

class Referenced;

struct ReferencedCounter {
    virtual ~ReferencedCounter() = default;

    virtual void addReferenced(const Referenced& value) = 0;

    virtual void removeReferenced(const Referenced& value) = 0;
};

void setReferencedCounter(ReferencedCounter* ptr);

void addReferenced(const Referenced& value);

void removeReferenced(const Referenced& value);

}

#endif
