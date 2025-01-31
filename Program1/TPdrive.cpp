// Author: Anushka Chougule 
// Date: January 17, 2025

#include "transposelist.h"
#include <iostream>
using namespace std;

//Prints the current list items 
void displayList(TransposeList& list) {
    cout << "List contents: " << endl;
    for (int i = 0; i < list.getCurrentSize(); i++) {
        cout << list.retrieve(i) << " " << endl;
    }
}

//Checks if list contains value
void checkAndSwap(TransposeList& list, int value) {
    cout << "Checking if list has " << value << endl;
    list.contains(value);
}

int main() {
    TransposeList testList;

    //Adding elements to list 
    cout << "Adding items to list" << endl;
    testList.add(5);
    testList.add(3);
    testList.add(8);
    testList.add(7);

    //Displaying list size and its contents
    cout << "List size: " << testList.getCurrentSize() << endl;
    displayList(testList);

    //checks and then swaps the values 
    checkAndSwap(testList, 5);
    cout << "List after swap: " << endl;
    displayList(testList);

    //Checking if the list contains items which are not added
    cout << "Checking if list has 12: ";
    if (testList.contains(12)) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }
    cout << "List after check for 12: " << endl;
    displayList(testList);

    //Removes an item from the list and displays the list size and contents
    cout << "Removing 8 from list" << endl;
    testList.remove(8);
    cout << "List size after removal: " << testList.getCurrentSize() << endl;
    displayList(testList);

    return 0;
}
