// Author: Anushka Chougule 
// Date: January 17, 2025

#include "CDLinkedList.h"
#include <iostream>
using namespace std;

int main() {
    CDLinkedList testList;

    //Adding elements to the list
    cout << "Adding elements to the list" << endl;
    testList.add(4);
    testList.add(11);
    testList.add(15);
    testList.add(20);

    //Printing the size and elements in the list 
    cout << "Current size: " << testList.getCurrentSize() << endl;
    cout << "Contents of the list: " << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << " " << endl;
    }

    //removing element from the list 
    cout << "Removing element 15" << endl;
    testList.remove(15);
    cout << "Current size: " << testList.getCurrentSize() << endl;

    //post-changes list
    cout << "List after removal: " << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << " " << endl;
    }

    cout << "Adding duplicate element" << endl;
    if (!testList.add(4)) {
        cout << "Duplicate element not added." << endl;
    }

    cout << "Current size: " << testList.getCurrentSize() << endl;

    //Attemps to retrive and element that is not valid 
    cout << "Attempting to retrieve element:" << endl;
    int outOfBoundsElement = testList.retrieve(6);
    if (outOfBoundsElement == -1) {
        cout << "Index is out of bounds." << endl;
    } else {
        cout << "Element at index: " << outOfBoundsElement << endl;
    }

    //Clears the entire list
    cout << "Clearing list." << endl;
    testList.clear();
    cout << "Size after clearing: " << testList.getCurrentSize() << endl;

    return 0;
}
