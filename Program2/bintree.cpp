// Program 2: Binary Search Tree (CSS 343)
// Author: Anushka Chougule
// Date: January 25, 2025
// ----------------------------------------------------------------------------

#include "bintree.h"
#include <iostream>
#include <algorithm>  
using namespace std;

// Default constructor
BinTree::BinTree() : root(nullptr) {}

// Copy constructor
BinTree::BinTree(const BinTree &other) {
    root = copyTree(other.root);
}

// Destructor
BinTree::~BinTree() {
    destroyTree(root);
}

//Helper Function
bool isNumber(const string &s) {
    if (s.empty()) {
        return false;
    }
    int start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    return all_of(s.begin() + start, s.end(), ::isdigit);
}

// Check if the tree is empty
bool BinTree::isEmpty() const {
    return root == nullptr;
}

// Insert a new node
bool BinTree::insert(const string &value) {
    return insertHelper(root, value);
}

// Retrieve a node based on data
bool BinTree::retrieve(const string &data, Node *&node) const {
    return retrieveHelper(root, data, node);
}

// Get the height of a node
int BinTree::getHeight(const string &data) const {
    Node *foundNode = nullptr;
    if (!retrieve(data, foundNode)) {
        return 0;
    }
    return getHeightHelper(foundNode);
}

// Display the tree in preorder
void BinTree::displayTree() const {
    if (root != nullptr) {
        cout << "Root: " << root->data << endl;
        displayTreeHelper(root, "     ");
    }
}


// Display the tree sideways
void BinTree::displaySideways() const {
    displaySidewaysHelper(root, 0);
}

// Assignment operator
BinTree &BinTree::operator=(const BinTree &other) {
    if (this != &other) {
        destroyTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

// Equality operator
bool BinTree::operator==(const BinTree &other) const {
    return compareTrees(root, other.root);
}

// Inequality operator
bool BinTree::operator!=(const BinTree &other) const {
    return !(*this == other);
}

// Prints tree using inorder traversal
ostream &operator<<(ostream &os, const BinTree &tree) {
    tree.inOrderPrint(tree.root, os);
    return os;
}

// Converts BST to array
void BinTree::bstreeToArray(string arr[]) {
    int index = 0;
    toArray(root, arr, index);
}

// Converts array to BST
void BinTree::arrayToBSTree(string arr[]) {
    int n = 0;
    while (!arr[n].empty()) ++n;  // Find the number of elements
    root = arrayToBST(arr, 0, n - 1);
}


// Helper functions
// Inserts a node recursively
bool BinTree::insertHelper(Node *&node, const string &data) {
    if (node == nullptr) {
        node = new Node(data);
        node->data = data;
        node->left = nullptr;
        node->right = nullptr;
        return true;
    }

    bool isNum = isNumber(data);
    bool nodeIsNum = isNumber(node->data);

    if (isNum && nodeIsNum) {
        int currentNodeValue = stoi(node->data);
        int newValue = stoi(data);

        if (newValue < currentNodeValue) {
            return insertHelper(node->left, data);
        } else if (newValue > currentNodeValue) {
            return insertHelper(node->right, data);
        }
    } else {
        if (data < node->data) {
            return insertHelper(node->left, data);
        } else if (data > node->data) {
            return insertHelper(node->right, data);
        }
    }

    return false;
}

// Retrieve a node recursively
bool BinTree::retrieveHelper(Node *node, const string &data, Node *&foundNode) const {
    if (node == nullptr) {
        foundNode = nullptr;
        return false;
    }
    if (node->data == data) {
        foundNode = node;
        return true;
    }

    if (data < node->data) {
        return retrieveHelper(node->left, data, foundNode);
    } else {
        return retrieveHelper(node->right, data, foundNode);
    }
}

// Get the height of a node recursively
int BinTree::getHeightHelper(Node *node) const {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = getHeightHelper(node->left);
    int rightHeight = getHeightHelper(node->right);
    return 1 + max(leftHeight, rightHeight);
}

// Displays the preorder
void BinTree::displayTreeHelper(Node *node, string prefix) const {
    if (node != nullptr) {
        cout << prefix << node->data << endl;
        string newPrefix = prefix + "    ";
        if (node->left != nullptr || node->right != nullptr) {
            if (node->left != nullptr) {
                displayTreeHelper(node->left, newPrefix + "L--- ");
            }
            if (node->right != nullptr) {
                displayTreeHelper(node->right, newPrefix + "R--- ");
            }
        }
    }
}

// Displays the sideways
void BinTree::displaySidewaysHelper(Node *node, int level) const {
    if (node == nullptr) {
        return;
    }
    displaySidewaysHelper(node->right, level + 1);
    for (int i = 0; i < level; i++) {
        cout << "    ";
    }
    cout << node->data << endl;
    displaySidewaysHelper(node->left, level + 1);
}

// Destroys the tree recursively
void BinTree::destroyTree(Node *&node) {
    if (node == nullptr) {
        return;
    }
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
    node = nullptr;
}

// Copies the tree recursively
Node* BinTree::copyTree(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node *newNode = new Node(node->data);
    newNode->data = node->data;
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);

    return newNode;
}

// In-order traversal 
void BinTree::inOrderPrint(Node *node, ostream &os) const {
    if (node != nullptr) {
        inOrderPrint(node->left, os);
        os << node->data << " ";
        inOrderPrint(node->right, os);
    }
}

// Converts the tree to an array 
void BinTree::toArray(Node *node, string arr[], int &index) const {
    if (node != nullptr) {
        toArray(node->left, arr, index);
        arr[index++] = node->data;
        toArray(node->right, arr, index);
    }
}

// Converts an array to a BST
Node* BinTree::arrayToBST(string arr[], int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    Node *node = new Node(arr[mid]); 
    node->left = arrayToBST(arr, start, mid - 1);
    node->right = arrayToBST(arr, mid + 1, end);
    return node;
}

// Compares 2 Trees
bool BinTree::compareTrees(Node *node1, Node *node2) const {
    if (!node1 && !node2) return true;
    if (!node1 || !node2) return false;
    return node1->data == node2->data &&
           compareTrees(node1->left, node2->left) &&
           compareTrees(node1->right, node2->right);
}
