//Author: Anushka Chougule 
//Course: CSS343
//Date: Feb 13, 2025

#ifndef GRAPHL
#define GRAPHL

#include "nodedata.h"
#include <iostream>
#include <fstream>
using namespace std;

//Max num nodes in graph:
int const MAXNODES_L = 101;

class GraphL{
public:
    //Constructor + Destructor
    GraphL();
    ~GraphL();

    
    void depthFirstSearch(); //does depth-first search
    void displayGraph(); //Displays built graph 
    int buildGraph(ifstream&); //Builds graph 
    
private:
    int size; //size of the nodes 
    struct EdgeNode; //EdgeNode structure
    
    //Pointer to the head, data and checks if node has been visited 
    struct GraphNode
    {
        EdgeNode* edgeHead;
        NodeData* data;
        bool visited;
    };

    //Array in which nodes are being stored
    GraphNode node_array[MAXNODES_L];

    //Pointer and index to thenext node
    struct EdgeNode
    {
        EdgeNode* nextEdge;
        int adjGraphNode;
    };

    //Helper functions
    void depthFirstSearchHelper(int value);
    void makeEmpty();
    
};
#endif 
