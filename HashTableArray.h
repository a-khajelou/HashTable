//
// Created by Arash Khajelou on 1/30/16.
//

#ifndef HASHTABLE_HASHTABLEARRAY_H
#define HASHTABLE_HASHTABLEARRAY_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

/*
 * Class HashTableArrat is the array implementation of the hash tables ! :) */

#define SIZE_KEY       16
#define SIZE_VALUE1    64
#define SIZE_VALUE2    16
#define DEFAULT_TABLESIZE    101
using namespace std;

class Node {
public :
    Node(const char *Key1 = "\0", const char *fName = "\0",
         const char *tele = "\0", const double sal = 0.0) {
        strcpy(Key, Key1);
        strcpy(FullName, fName);
        strcpy(Tele_No, tele);
        Salary = sal;
        Tax = 0.005 * Salary;
        next = NULL;
    }

    char Key[SIZE_KEY];
    char FullName[SIZE_VALUE1];
    char Tele_No[SIZE_VALUE2];
    double Salary;
    double Tax;
    Node *next;
};

class HashTableArray {
private:

    int table_size;
    Node **table;
    int size;

    long hashString(char *_key){//start hashString
        int n = strlen(_key);
        long h = 0;
        for (int i = 0; i < n; i++) {
            //To get almost fair distributions of nodes over the array
            h = (h << 3) ^ _key[i];
        }
        return abs(h % table_size);
    }//end hashString

    Node *find(char *_key){ //start find
        int bucket = hashString(_key);
        Node *temp = table[bucket];
        while (temp != NULL) {
            if (strcmp(_key, temp->Key) == 0) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }//end find

    Node *current_entry;
    int current_index;

public:

    //constructor
    HashTableArray(int _T = DEFAULT_TABLESIZE) {
        size = 0;
        table_size = _T;
        table = new Node *[table_size];
        for (int i = 0; i < table_size; i++) {
            table[i] = NULL;
        }
    }

    //destructor
    virtual ~Hashtable() {
        removeAll();
        delete[] table;
    }

    bool put(Node *_node) {//start put
        if (find(_node->Key) != NULL) {
            return false;
        }
        Node *entry = new Node(_node->Key, _node->FullName, _node->Tele_No, _node->Salary);
        int bucket = hashString(_node->Key);
        entry->next = table[bucket];
        table[bucket] = entry;
        size++;
        return true;
    }//end put

    bool get(Node * _node){
        {//start get
            Node *temp = find(_node->Key);
            if (temp == NULL) {
                _node->FullName[0] = '\0';
                return false;
            }
            else {
                strcpy(_node->FullName, temp->FullName);
                strcpy(_node->Tele_No, temp->Tele_No);
                _node->Salary = temp->Salary;
                _node->Tax = temp->Tax;
                return true;
            }
        }//end get
    }

    bool contains(char *_key){//start contains
        if (find(_key) == NULL) {
            return false;
        }
        else {
            return true;
        }
    }//end contains

    bool remove(char *_key){//start remove
        int bucket = hashString(_key);
        Node *temp = table[bucket];
        if (temp == NULL) {
            return false;
        }
        else if (strcmp(_key, temp->Key) == 0) {
            table[bucket] = temp->next;
            delete temp;
            size--;
            return true;
        }
        else {
            Node *temp_next = temp->next;
            while (temp_next != NULL) {
                if (strcmp(_key, temp_next->Key) == 0) {
                    temp->next = temp_next->next;
                    delete temp_next;
                    size--;
                    return true;
                }
                temp = temp->next;
                temp_next = temp_next->next;
            }
        }
        return false;
    }//end remove

    void removeAll(){//start removeAll
        for (int i = 0; i < table_size; i++) {
            Node *temp = table[i];
            while (temp != NULL) {
                Node *next = temp->next;
                disp(temp);
                delete temp;
                temp = next;
            }
        }
        size = 0;
    }//end removeAll

    int getSize(){
        return size;
    }

    void initIterator(){//start initIterator
        current_entry = NULL;
        current_index = table_size;
        for (int i = 0; i < table_size; i++) {
            if (table[i] == NULL) {
                continue;
            }
            else {
                current_entry = table[i];
                current_index = i;
                break;
            }
        }
    }//end initIterator

    bool hasNext(){
        if (current_entry == NULL) {
            return false;
        }
        else {
            return true;
        }
    }

    void getNextKey(char *_key){
        if (current_entry == NULL) {
            _key[0] = '\0';
            return;
        }
        strcpy(_key, current_entry->Key);
        if (current_entry->next != NULL) {
            current_entry = current_entry->next;
        }
        else {
            for (int i = current_index + 1; i < table_size; i++) {
                if (table[i] == NULL) {
                    continue;
                }
                current_entry = table[i];
                current_index = i;
                return;
            }
            current_entry = NULL;
            current_index = table_size;
        }
    }

    friend void disp(Node *_node) {
        cout << "\nKey:      " << _node->Key << "\nFullName: "
        << _node->FullName << "\nTele.:    " << _node->Tele_No << "\nSalary:   "
        << setprecision(12) << _node->Salary << "\nTax:      " << _node->Tax << endl;
    }
};

void dispAll(HashTableArray *hashTableArray) {
    Node N1;
    cout << "\n\nCurrent nodes in hashtable:" << endl;
    hashTableArray->initIterator();
    while (hashTableArray->hasNext()) {
        hashTableArray->getNextKey(N1.Key);
        hashTableArray->get(&N1);
        disp(&N1);
    }
}

#endif //HASHTABLE_HASHTABLEARRAY_H
