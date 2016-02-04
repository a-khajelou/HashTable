//
// Created by arash on 12/19/15.
//

#ifndef HASHTABLE_HASHTABLE_LINK_H
#define HASHTABLE_HASHTABLE_LINK_H

#include <list>
#include <vector>
#include <iostream>
#include <assert.h>
#include "HashTableNode.h"

/*
 * this is linked list implementation of HashTableLink , this class uses the STD::List to implement hashtables !
 */

class HashTableLink {
private:
    std::vector<std::list<HashTableNode>> lists;
    int currentSize;
    int maxSize; //its better to set this a prime number

public:
    HashTableLink(int _maxSize) {
        this->maxSize = _maxSize;
    }

    // Adds an item to the Hash Table.
    bool insert(HashTableNode &_hashTableNode) {
        std::list<HashTableNode> &tmpList = this->lists[_hashTableNode.hash(this->maxSize)];
        if (find(tmpList.begin(), tmpList.end(), _hashTableNode) != tmpList.end())
            return false;
        tmpList.push_back(_hashTableNode);

        if (++this->currentSize > this->lists.size()) {
            //we must rehash the table ! :|
            //no need yet
        }

        return true;
    }

    // De-allocates all memory used for the Hash Table.
    void makeEmpty() {
        for(int i=0; i< this->lists.size() ; i++){
            this->lists[i].clear();
        }
    }

    bool contains(const HashTableNode & _hashTableNode){
        const std::list<HashTableNode> &tmpList = this->lists[_hashTableNode.hash(this->maxSize)];
        return find(tmpList.begin(), tmpList.end(), _hashTableNode) != tmpList.end();
    }

    // De-allocates the memory used for the Hash Table item.
    // Deletes an Item by key from the Hash Table.
    // Returns true if the operation is successful.
    bool remove(const HashTableNode & _hashTableNode){
        std::list<HashTableNode> &tmpList = this->lists[_hashTableNode.hash(this->maxSize)];
        std::list<HashTableNode>::iterator iter = find(tmpList.begin(), tmpList.end(), _hashTableNode);

        if(iter == tmpList.end())
            return false;
        tmpList.erase(iter);
        --this->currentSize;
        return true;
    }
};


#endif //HASHTABLE_HASHTABLE_LINK_H
