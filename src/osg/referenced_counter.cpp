#include <osg/referenced_counter.hpp>

#include <osg/Referenced>

#include <atomic>

namespace osg {

namespace {

std::atomic<ReferencedCounter*> referencedCounter;

}

void setReferencedCounter(ReferencedCounter* ptr) {
    referencedCounter = ptr;
}

void addReferenced(const Referenced& value)
{
    if (ReferencedCounter* const ptr = referencedCounter.load())
        ptr->addReferenced(value);
}

void removeReferenced(const Referenced& value) {
    if (ReferencedCounter* const ptr = referencedCounter.load())
        ptr->removeReferenced(value);
}

}
