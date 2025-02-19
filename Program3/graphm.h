//Author: Anushka Chougule 
//Course: CSS343
//Date: Feb 13, 2025

#ifndef GRAPHM_H
#define GRAPHM_H

#include "nodedata.h"
#include <fstream>
#include <iostream>

using namespace std;

//Max num nodes in graph:
int const MAXNODES_M = 101;

class GraphM{
public:

    //Constructor   
    GraphM();

    //void values which displays shortest path 
    void display(int from, int to);
    void findShortestPath();
    void displayAll();

    //Boolean values which finds and removes edges 
    bool insertEdge(int from, int to, int dist);
    bool removeEdge(int from, int to);

    //Integer value which builds the graph 
    int buildGraph(ifstream&);


private:
    //Defines shortest distance, previous node and flag nodes visited
    struct TableType{
        int distance;
        int path;
        bool visited;
    };

    //Defines size, store edge distance, array to store  and matrix
    int size;
    NodeData data[MAXNODES_M];
    TableType T[MAXNODES_M][MAXNODES_M];  
    int C[MAXNODES_M][MAXNODES_M];
    
    //Helper functions
    void findPath(int from, int to);
    void findData(int from, int to);
};
#endif 
