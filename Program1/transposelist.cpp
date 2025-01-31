//Author: Anushka Chougule
//Date: Jan 17, 2025

#include "transposelist.h"
#include <iostream>
using namespace std;

bool TransposeList::contains(int anEntry) 
{
    DListNode* node = findNode(anEntry);
    if (node == nullptr){
        return false;
    } 

    if (node->prev != header) 
    {
        DListNode* prevNode = node->prev;

        node->prev = prevNode->prev;
        prevNode->prev->next = node;

        prevNode->next = node->next;
        node->next->prev = prevNode;

        node->next = prevNode;
        prevNode->prev = node;
    }
    return true;
}
