// Author: Anushka Chougule 
// Date: January 17, 2025

#include <iostream>
#include "CDLinkedList.h"
using namespace std;

//Constructor: For empty CD linked list
CDLinkedList::CDLinkedList() {
    header = new DListNode;
    header->next = header;
    header->prev = header;
    traverseCount = 0;
}

//Copy Constructor
CDLinkedList::CDLinkedList(const CDLinkedList& rhs) {
    DListNode* curr = rhs.header->next;
    while (curr != rhs.header) {
        add(curr->item);
        curr = curr->next;
    }
}

//Destructor: deletes header nodes and keeps memory leaks in check
CDLinkedList::~CDLinkedList() {
    clear();
    delete header;
}

//Size of the list: returns the value
int CDLinkedList::getCurrentSize() const {
    int size = 0;
    DListNode* curr = header->next;
    while (curr != header) {
        size++;
        curr = curr->next;
    }
    return size;
}

//Checks if list is empty
bool CDLinkedList::isEmpty() const {
    return header->next == header;
}

//Adds new entry to the list
bool CDLinkedList::add(int newEntry) {
    if (contains(newEntry)) {
        return false;
    }

    DListNode* newNode = new DListNode;
    newNode->item = newEntry;
    newNode->next = header->next;
    newNode->prev = header;
    header->next->prev = newNode;
    header->next = newNode;

    traverseCount++;
    return true;
}

//Removes specific entry from list
bool CDLinkedList::remove(int anEntry) {
    DListNode* removeNode = findNode(anEntry);
    if (removeNode == nullptr) return false;

    removeNode->prev->next = removeNode->next;
    removeNode->next->prev = removeNode->prev;
    delete removeNode;

    return true;
}

//Clears all "nodes"/entries from list 
void CDLinkedList::clear() {
    DListNode* curr = header->next;
    while (curr != header) {
        DListNode* deleteNode = curr;
        curr = curr->next;
        delete deleteNode;
    }
    header->next = header;
    header->prev = header;
}

//Checks if the said value is contained in the list
bool CDLinkedList::contains(int anEntry) {
    DListNode* curr = header->next;
    while (curr != header) {
        traverseCount++;
        if (curr->item == anEntry) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

//Returns traverseCount
int CDLinkedList::getTraverseCount() const {
    return traverseCount;
}

//Retrieves element from a specific index 
int CDLinkedList::retrieve(int index) const {
    DListNode* curr = header->next;
    int count = 0;
    while (curr != header && count < index) {
        curr = curr->next;
        count++;
    }

    if (curr != header) {
        return curr->item;
    } else {
        return -1;
    }
}

//Finds + returns node withs speciifc element 
DListNode* CDLinkedList::findNode(int anEntry) {
    DListNode* curr = header->next;
    while (curr != header) {
        traverseCount++;
        if (curr->item == anEntry) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

//Resets the traverseCount
void CDLinkedList::resetTraversalCount() {
    traverseCount = 0;
}
