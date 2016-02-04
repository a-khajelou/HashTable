#include <iostream>
#include "HashTableNode.h"
#include "Student.h"
#include "HashTableLink.h"
#include "HashTable.h"
#include "HashTableArray.h"

using namespace std;

int main() {
    HashTableNode *hashTableNode = new Student("Arash", 91521122);

    HashTable hashTable(101);

    char temp1[SIZE_KEY];
    HashTableArray *hashtable = new HashTableArray();

    Node N1("389", "Qoli", "8216734", 22123.267);

    if (!hashtable->contains(N1.Key)) {
        cout << "\nAdding node:  ";
        disp(&N1);
        hashtable->put(&N1);
    }

    strcpy(N1.Key, "320");
    strcpy(N1.FullName, "Sasan");
    strcpy(N1.Tele_No, "7231144");
    N1.Salary = 19834.575;
    if (!hashtable->contains(N1.Key)) {
        cout << "\nAdding node:  ";
        disp(&N1);
        hashtable->put(&N1);
    }

    strcpy(N1.Key, "768");
    strcpy(N1.FullName, "Hassan");
    strcpy(N1.Tele_No, "7689876");
    N1.Salary = 45124.755;
    if (!hashtable->contains(N1.Key)) {
        cout << "\nAdding node:  ";
        disp(&N1);
        hashtable->put(&N1);
    }

    strcpy(N1.Key, "756");
    strcpy(N1.FullName, "Ali");
    strcpy(N1.Tele_No, "9874545");
    N1.Salary = 43554.125;
    if (!hashtable->contains(N1.Key)) {
        cout << "\nAdding node:  ";
        disp(&N1);
        hashtable->put(&N1);
    }

    dispAll(hashtable);

    strcpy(temp1, "314");
    hashtable->remove(temp1);
    cout << "\n\nAfter removing 314:" << endl;
    dispAll(hashtable);
    cout << "\n\nDestroying hashtable:" << endl;
    delete hashtable;
    return 0;

    return 0;
}