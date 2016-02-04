//
// Created by arash on 12/19/15.
//

#ifndef HASHTABLE_STUDENT_H
#define HASHTABLE_STUDENT_H


#include "HashTableNode.h"

class Student : public HashTableNode {
private:
    long id;
    char *name;
    //and some other properties ... :|

public:
    //override
    long hash(long _arraySize) const {
        if(this->id < 0)
            return this->hash(this->id+_arraySize);
        return this->id%_arraySize;
    }

    Student(){

    }

    Student(char *_name, long _id){
        this->name = _name;
        this->id = _id;
    }

    long getId(){
        return this->id;
    }

    void setId(long _id){
        this->id = _id;
    }

    char *getName(){
        return this->name;
    }

    void setName(char* _name){
        this->name = _name;
    }

};


#endif //HASHTABLE_STUDENT_H
