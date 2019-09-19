
#ifndef Set_h
#define Set_h
#include "SetInterface.h"

template<typename T>
class Set : public SetInterface<T> {
public:
    Set() {}
    ~Set() {}
    
    /** Inserts item into the set, if the container doesn't
     already contain an element with an equivalent value.
     @return: pair.first = pointer to item
     pair.second = true if successfully inserted, else false. */
    //virtual Pair<T*, bool> insert(const T& item) = 0;
    bool insert(const T& item) = 0;
    
    /** @return: the number of elements removed from the Set. */
    size_t erase(const T& item) = 0;
    
    /** Removes all items from the set. */
    void clear() = 0;
    
    /** @return: the number of elements contained by the Set. */
    size_t size() const = 0;
    
    /** @return: return 1 if contains element equivalent to item, else 0. */
    size_t count(const T& item) const = 0;
    
    /** @return: string representation of items in Set. */
    std::string toString() const = 0;
};

#endif /* Set_h */
