//
// Created by Arash Khajelou on 1/30/16.
//


#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
using namespace std;

struct Item
{
    string key;
    Item * next;
};

class LinkedList
{
private:
    // Head is a reference to a list of data nodes.
    Item * head;

    // Length is the number of data nodes.
    int length;

public:
    // Constructs the empty linked list object.
    // Creates the head node and sets length to zero.
    LinkedList(){
        head = new Item;
        head -> next = NULL;
        length = 0;
    }

    // Inserts an item at the end of the list.
    void insertItem( Item * newItem ){
        if (!head -> next)
        {
            head -> next = newItem;
            length++;
            return;
        }
        Item * p = head;
        Item * q = head;
        while (q)
        {
            p = q;
            q = p -> next;
        }
        p -> next = newItem;
        newItem -> next = NULL;
        length++;
    }

    // Removes an item from the list by item key.
    // Returns true if the operation is successful.
    bool removeItem( string itemKey ){
        if (!head -> next) return false;
        Item * p = head;
        Item * q = head;
        while (q)
        {
            if (q -> key == itemKey)
            {
                p -> next = q -> next;
                delete q;
                length--;
                return true;
            }
            p = q;
            q = p -> next;
        }
        return false;
    }

    // Searches for an item by its key.
    // Returns a reference to first match.
    // Returns a NULL pointer if no match is found.
    Item * getItem( string itemKey ){
        Item * p = head;
        Item * q = head;
        while (q)
        {
            p = q;
            if ((p != head) && (p -> key == itemKey))
                return p;
            q = p -> next;
        }
        return NULL;
    }

    // Displays list contents to the console window.
    void printList(){
        if (length == 0)
        {
            cout << "\n{ }\n";
            return;
        }
        Item * p = head;
        Item * q = head;
        cout << "\n{ ";
        while (q)
        {
            p = q;
            if (p != head)
            {
                cout << p -> key;
                if (p -> next) cout << ", ";
                else cout << " ";
            }
            q = p -> next;
        }
        cout << "}\n";
    }

    // Returns the length of the list.
    int getLength(){
        return length;
    }

    // De-allocates list memory when the program terminates.
    ~LinkedList(){
        Item * p = head;
        Item * q = head;
        while (q)
        {
            p = q;
            q = p -> next;
            if (q) delete p;
        }
    }
};

#endif