// Program 2: Binary Search Tree (CSS 343)
// Author: Anushka Chougule
// Date: January 25, 2025
// ----------------------------------------------------------------------------

#include <iostream>
#include "bintree.h"
using namespace std;

int main() {

    BinTree example;

    // Testing INSERT method
    cout << "Testing INSERT method" << endl;
    example.insert("20");
    example.insert("99");
    example.insert("56");
    example.insert("52");
    example.insert("13");
    example.insert("63");

    // Testing Tree-PREORDER method
    cout << "\nTesting PREORDER method" << endl;
    example.displayTree();

    // Testing Tree-SIDEWAYS method
    cout << "\nTesting SIDEWAYS method" << endl;
    example.displaySideways();

    // Testing Retrieve method
    cout << "\nTesting RETRIEVE method" << endl;
    Node *foundNode = nullptr; 
    if (example.retrieve("40", foundNode)) {
        cout << "Node: " << foundNode->data << endl;
    } else {
        cout << "No Node Found." << endl;
    }

    // Testing HEIGHT method
    cout << "\nTesting HEIGHT method" << endl;
    cout << "Height of Node 56: " << example.getHeight("56") << endl;
    cout << "Height of Node 99: " << example.getHeight("99") << endl;
    cout << "Height of Node 13: " << example.getHeight("13") << endl;

    // Testing TREE TO ARRAY method
    cout << "\nTesting TREE TO ARRAY method" << endl;
    string array[100]; 
    example.bstreeToArray(array);  // Convert tree to array
    for (int i = 0; !array[i].empty(); ++i) {  // Loop through the array and print values
        cout << array[i] << " ";
    }
    cout << endl;

    // Testing ARRAY TO TREE method
    cout << "\nTesting ARRAY TO TREE method" << endl;
    BinTree example1;
    example1.arrayToBSTree(array);  // Convert array back to tree
    example1.displayTree();

    // Testing COMPARE method
    cout << "\nTesting COMPARE method" << endl;
    BinTree example2;
    example2.insert("50");
    example2.insert("30");
    example2.insert("70");
    example2.insert("20");
    example2.insert("40");
    example2.insert("60");
    example2.insert("80");

    cout << "\nChecking if trees are equal:" << endl;
    if (example == example2) {
        cout << "Trees ARE equal." << endl;
    } else {
        cout << "Trees are NOT equal." << endl;
    }

    // Testing ASSIGNMENT method
    cout << "\nTesting ASSIGNMENT method" << endl;
    BinTree example3;
    example3 = example;  // Use assignment operator
    cout << "Tree after assignment operator:" << endl;
    example3.displayTree();

    return 0;
}
