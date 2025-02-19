//---------------------------------------------------------------------------
// driver.cpp
//---------------------------------------------------------------------------
// This code tests the basic functionality of the classes to perform
// Dijkstra's algorithm and depth-first search.
// It is not meant to exhaustively test the class.
//
// Assumptions:
// -- Students can follow the directions to interface with this file.
// -- Text files "data31.txt" and "data32.txt" are formatted as described.
// -- Data file dataUWB provides an additional data set for part 1;
//    it must be edited, as it starts with a description of how to use it.
//---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "graphl.h"
#include "graphm.h"

using namespace std;

int main() {
    // Part 1: Dijkstra's Algorithm
    cout << "\nPart 1" << endl;
    ifstream infile1("data31.txt");
    
    if (!infile1) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    // For each graph, find the shortest path from every node to all other nodes
    while (!infile1.eof()) {
        GraphM G;
        if (G.buildGraph(infile1) > 0) {
            G.findShortestPath();
            cout << "Display all shortest paths" << endl;
            G.displayAll(); // Display shortest distance, path to cout

            // Display specific shortest paths
            cout << "Display a shortest path from data[3] to data[1]" << endl;
            G.display(3, 1); // Display path from node 3 to 1

            cout << "Display a shortest path from data[1] to data[2]" << endl;
            G.display(1, 2);

            cout << "Display a shortest path from data[1] to data[4]" << endl;
            G.display(1, 4);
        }
    }

    // Part 2: Depth-First Search
    cout << "\nPart 2" << endl;
    ifstream infile2("data32.txt");
    
    if (!infile2) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    // For each graph, find the depth-first search ordering
    while (!infile2.eof()) {
        GraphL G;
        if (G.buildGraph(infile2) > 0) {
            cout << "Display Graph" << endl;
            G.displayGraph();
            
            cout << "Display DFS" << endl;
            G.depthFirstSearch(); // Find and display depth-first ordering
        }
    }

    cout << endl;
    return 0;
}
