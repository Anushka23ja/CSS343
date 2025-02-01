// bintree.h---------------------------------------------------------------
// ADT Binary Search Tree using nodes
// ----------------------------------------------------------------------------
// Program 2: Binary Search Tree (CSS 343)
// Author: Anushka Chougule
// Date: January 25, 2025
// ----------------------------------------------------------------------------

#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <string>
using namespace std;

const int ARRAYSIZE = 100;

struct Node {
  string data;
  Node *left;
  Node *right;
  Node(string val) : data(val), left(nullptr), right(nullptr) {}
};

class BinTree {
  friend ostream &operator<<(ostream &, const BinTree &);

public:
  // Constructors
  BinTree();                                
  BinTree(const BinTree &);                  

  // Destructor
  ~BinTree();                               

  // Required public methods
  bool isEmpty() const;                      
  bool insert(const string &data);          
  bool retrieve(const string &, Node *&) const;  
  int getHeight(const string &) const;      

  // Display the tree in preorder
  void displayTree() const;

  // Display the tree sideways
  void displaySideways() const;

  // Overload operators
  BinTree &operator=(const BinTree &);       
  bool operator==(const BinTree &) const;    
  bool operator!=(const BinTree &) const;    

  // Miscellaneous Functions
  void bstreeToArray(string[]);              
  void arrayToBSTree(string[]);              

private:
  Node *root;                                

  // Helper functions 
  bool insertHelper(Node *&, const string &);                 // Recursive helper
  bool retrieveHelper(Node *, const string &, Node *&) const; // Recursive helper
  int getHeightHelper(Node *) const;                          // Helper for height 
  void displayTreeHelper(Node *, string prefix) const;        // Recursive display helper 
  void displaySidewaysHelper(Node *, int) const;              // Recursive sideways display helper
  Node *copyTree(Node *);                                     // Copy helper
  void destroyTree(Node *&node);                              // Helper for destroying tree
  void inOrderPrint(Node *, ostream &) const;                 // Helper for inorder printing
  void toArray(Node *node, string arr[], int &index) const;   // Helper Converting tree to array
  Node * arrayToBST(string arr[], int start, int end);        // Helper Converting array to BST
  bool compareTrees(Node *, Node *) const;                    // Helper for tree comparison
  void makeEmpty();                                           // Emptying tree
};

#endif 
