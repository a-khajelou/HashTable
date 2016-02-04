//
// Created by Arash Khajelou on 1/30/16.
//

#ifndef HashTable_h
#define HashTable_h

#include "LinkedList.h"

/*
 * Class HashTable contains the hashtable which implements my own linked list to create the structure */

class HashTable {
private:

    // Array is a reference to an array of Linked Lists.
    LinkedList *array;

    // Length is the size of the Hash Table array.
    int length;

    // Returns an array location for a given item key.
    int hash(string itemKey) {
        int value = 0;
        for (int i = 0; i < itemKey.length(); i++)
            value += itemKey[i];
        return (value * itemKey.length()) % length;
    }

public:

    // Constructs the empty Hash Table object.
    // Array length is set to 13 by default.
    HashTable(int tableLength = 13) {
        if (tableLength <= 0) tableLength = 13;
        array = new LinkedList[tableLength];
        length = tableLength;
    }

    // Adds an item to the Hash Table.
    void insertItem(Item *newItem) {
        int index = hash(newItem->key);
        array[index].insertItem(newItem);
    }

    // Deletes an Item by key from the Hash Table.
    // Returns true if the operation is successful.
    bool removeItem(string itemKey) {
        int index = hash(itemKey);
        return array[index].removeItem(itemKey);
    }

    // Returns an item from the Hash Table by key.
    // If the item isn't found, a null pointer is returned.
    Item *getItemByKey(string itemKey) {
        int index = hash(itemKey);
        return array[index].getItem(itemKey);
    }

    // Display the contents of the Hash Table to console window.
    void printTable() {
        cout << "\n\nHash Table:\n";
        for (int i = 0; i < length; i++) {
            cout << "Bucket " << i + 1 << ": ";
            array[i].printList();
        }
    }

    // Prints a histogram illustrating the Item distribution.
    void printHistogram() {
        cout << "\n\nHash Table Contains ";
        cout << getNumberOfItems() << " Items total\n";
        for (int i = 0; i < length; i++) {
            cout << i + 1 << ":\t";
            for (int j = 0; j < array[i].getLength(); j++)
                cout << " X";
            cout << "\n";
        }
    }

    // Returns the number of locations in the Hash Table.
    int getLength() {
        return length;
    }

    // Returns the number of Items in the Hash Table.
    int getNumberOfItems() {
        int itemCount = 0;
        for (int i = 0; i < length; i++) {
            itemCount += array[i].getLength();
        }
        return itemCount;
    }

    // De-allocates all memory used for the Hash Table.
    ~HashTable() {
        delete[] array;
    }
};

#endif

