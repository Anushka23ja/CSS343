#include "mtflist.h"
#include <iostream>
using namespace std;

int main() {
    MtfList testList; 

    cout << "Adding elements to MtfList" << endl;
    testList.add(2);
    testList.add(9);
    testList.add(12);
    testList.add(4);

    cout << "Current size: " << testList.getCurrentSize() << endl;
    cout << "Contents of the list: " << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << " " << endl;
    }

    cout << "Checking if list contains 9" << endl;
    testList.contains(9);

    cout << "Contents of the list after update: " << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << " " << endl;
    }

    cout << "Checking if list contains 12" << endl;
    if (testList.contains(12)) {
        cout << "Element 12 was found and moved to the front. Update completed." << endl;
    } else {
        cout << "Element 12 was not found. No update performed." << endl;
    }

    cout << "Contents of the list after update: " << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << " " << endl;
    }

    cout << "Checking if list contains 20" << endl;
    if (testList.contains(20)) {
        cout << "Element 20 was found and moved to the front." << endl;
    } else {
        cout << "Element 20 was not found. No update performed." << endl;
    }

    cout << "Rechecking if list contains 12 (It should remain at the front)" << endl;
    if (testList.contains(12)) {
        cout << "Element 12 is still at the front." << endl;
    } else {
        cout << "Element 12 was not found." << endl;
    }

    cout << "Contents of the list after rechecking 12: " << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << " " << endl;
    }

    cout << "Adding element 20 to MtfList" << endl;
    testList.add(20);
    cout << "Contents of the list after adding 20: " << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << " " << endl;
    }

    cout << "Trying to add duplicate element 20" << endl;
    if (testList.add(20)) {
        cout << "Element 20 was successfully added." << endl;
    } else {
        cout << "Element 20 already exists. Not added." << endl;
    }

    cout << "Final contents of the list: " << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << " " << endl;
    }

    return 0;
}
