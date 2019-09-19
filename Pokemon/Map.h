//
//  Map.h
//  Pokemon
//
//  Created by Sam Hopkins on 6/15/18.
//  Copyright © 2018 Sam Hopkins. All rights reserved.
//

#ifndef Map_h
#define Map_h
#include "MapInterface.h"
#include <string>

template <typename K, typename V>
class Map : public MapInterface<K, V> {
public:
    static const int HashTableSize = 31;
    static const int BonusHashTableSize = 7;
    
    Map() {}
    ~Map() {}
    
    /** Read/write index access operator.
     If the key is not found, an entry is made for it.
     @return: Read and write access to the value mapped to the provided key. */
    V& operator[](const K& key) = 0;
    
    /** @return: the number of elements removed from the Map. */
    size_t erase(const K& key) = 0;
    
    /** Removes all items from the Map. */
    void clear() = 0;
    
    /** @return: number of Key-Value pairs stored in the Map. */
    size_t size() const = 0;
    
    /** @return: maximum number of Key-Value pairs that the Map can hold. */
    size_t max_size() const = 0;
    
    /** @return: string representation of Key-Value pairs in Map. */
    std::string toString() const = 0;
};

#endif /* Map_h */
