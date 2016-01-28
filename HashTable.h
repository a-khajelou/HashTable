//
// Created by arash on 12/19/15.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <list>
#include <vector>
#include <iostream>
#include "HashTableNode.h"

/*
 * this is linked list implementation of HashTable
 */

class HashTable {
private:
    std::vector<std::list<HashTableNode>> lists;
    int currentSize;
    int maxSize; //its better to set this a prime number

public:
    HashTable(int _maxSize) {
        this->maxSize = _maxSize;
    }

    bool insert(HashTableNode &_hashTableNode) {
        std::list<HashTableNode> &tmpList = this->lists[_hashTableNode.hash(this->maxSize)];
        if (find(tmpList.begin(), tmpList.end(), _hashTableNode) != tmpList.end())
            return false;
        tmpList.push_back(_hashTableNode);

        if (++this->currentSize > this->lists.size()) {
            //we must rehash the table ! :|
        }
        return true;
    }

    void makeEmpty() {

    }

    void operator[](long _id){
        std::cout<<"Salam \n";
    }
};


#endif //HASHTABLE_HASHTABLE_H
