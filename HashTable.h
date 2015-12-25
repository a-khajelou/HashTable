//
// Created by arash on 12/19/15.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <bits/stl_bvector.h>
#include <bits/stl_list.h>
#include "HashTableNode.h"

class HashTable {
private:
    std::vector<std::list<HashTableNode>> lists ;
    int currentSize;
    int maxSize ; //its better to set this a prime number

public:
    HashTable(){}
    void insert(HashTableNode & _hashTableNode){
        std::list<HashTableNode> & tmpList = this->lists[_hashTableNode.hash(this->maxSize)];
    }
};


#endif //HASHTABLE_HASHTABLE_H
