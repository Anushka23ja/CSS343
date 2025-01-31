//Author: Anushka Chougule 
//Jan 16, 2025
//mtflist.h file: declares the method prototypes

#ifndef MTFLIST_H
#define MTFLIST_H
#include "CDLinkedList.h"

class MtfList: public CDLinkedList {
public:
    bool contains(int anEntry);
};

#endif