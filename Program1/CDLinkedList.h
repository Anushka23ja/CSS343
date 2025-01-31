//Author: Anushka Chougule
//Date: Jan 17, 2025

//CDLinkedList.h file: declares the method prototypes
#ifndef CDLINKEDLIST_H
#define CDLINKEDLIST_H

struct DListNode {
    int item;
     DListNode *prev;
     DListNode *next;
};

class CDLinkedList {
public:
    CDLinkedList();
    CDLinkedList(const CDLinkedList& rhs);
    virtual ~CDLinkedList();

    int getCurrentSize() const;
    bool isEmpty() const;

    bool add(int newEntry);
    bool remove(int anEntry);
    void clear();

    virtual bool contains(int anEntry);
    int getTraverseCount() const;
    int retrieve(int index) const;
    DListNode* findNode(int anEntry) ;
    void resetTraversalCount();

protected:
    DListNode* header; 
    int traverseCount;
};

#endif
