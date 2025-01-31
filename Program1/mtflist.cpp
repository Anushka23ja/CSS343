//Author: Anushka Chougule
//Date: Jan 17, 2025

#include "mtflist.h"
#include <iostream>
using namespace std;

//checks if the entry is present and moves it to the front 
bool MtfList::contains(int anEntry){
    DListNode* current = header->next;
    while(current != header){
        traverseCount++;
        if(current->item == anEntry){
            if(current != header->next){
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current->next = header->next;
                current->prev = header;
                header->next->prev = current;
                header->next = current;
            }
            return true;
        }
        current = current->next;
    }
    return false;
}
