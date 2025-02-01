// Program 2: Binary Search Tree (CSS 343)
// Author: Anushka Chougule
// Date: January 25, 2025
// ----------------------------------------------------------------------------

#include "bintree.h"
#include <fstream>
#include <iostream>
#include <cctype>

using namespace std;

// Function to build the tree from the input file
void buildTree(BinTree &T, ifstream &infile) {
    string s;
    for (;;) {
        infile >> s;

        // End the loop if end-of-line or end-of-file is encountered
        if (s == "$$")
            break; // at end of one line
        if (infile.eof())
            break; // no more lines of data

        string data = s; // data takes a string
        // Would do a setData if there were more than a string
        bool success = T.insert(s);
    }
}

// Function to print the array elements
void printArray(string a[]) {
    for (int i = 0; i < ARRAYSIZE; i++) {
        if (!a[i].empty())
            cout << a[i] << ' ';
    }
    cout << endl;
}

int main() {
    // Test the fileread method
    ifstream infile("inputdata.txt");
    
    if (!infile) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    cout << "Reading nodes from a file" << endl;
    
    while (!infile.eof()) {
        cout << "------------------------------" << endl;
        
        BinTree filetree;
        
        // Build the tree from the file
        buildTree(filetree, infile);

        // Testing sideway print
        cout << "Sideway print: " << endl;
        filetree.displaySideways();

        // Display tree
        cout << "Display tree: " << endl;
        filetree.displayTree();

        // Inorder traversal display
        cout << "Inorder: " << filetree << endl;

        // Test getHeight and retrieve methods
        cout << "Test retrieve and getHeight" << endl;
        string testnode = "18";
        Node *addr;
        bool found = filetree.retrieve(testnode, addr);
        cout << "Retrieve " << testnode << (found ? ": found" : ": not found") << endl;
        
        if (found)
            cout << "Node address = " << addr << endl;
        
        cout << "Height of node " << testnode << " is " << filetree.getHeight(testnode) << endl;

        // Copy tree and check if they are the same
        BinTree copytree(filetree);
        cout << "Copy Tree: " << copytree << endl;
        
        BinTree T = filetree;
        cout << "Assign Tree: " << T << endl;

        // Comparison checks
        cout << "Are they same? " << ((copytree == T) ? " yes " : " no") << endl;
        cout << "Are they different? " << ((copytree != T) ? " yes " : " no") << endl;

        // Test BST to Array and Array to BST conversion
        cout << "BST to Array" << endl;
        string ndarray[ARRAYSIZE];
        
        // Copy the original tree to preserve it
        BinTree original(filetree);

        // Empty the original tree after converting to array
        filetree.bstreeToArray(ndarray);
        printArray(ndarray);

        cout << "Array to BST: should balance the tree" << endl;
        filetree.arrayToBSTree(ndarray);
        filetree.displaySideways();
        filetree.displayTree();

        // Compare the original tree with the recovered tree
        cout << "Compare the original tree and recovered tree" << endl;
        cout << "Are they same? " << ((original == filetree) ? " yes " : " no") << endl;
        cout << "Are they different? " << ((original != filetree) ? " yes " : " no") << endl;
    }

    return 0;
}
