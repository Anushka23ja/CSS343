//Author: Anushka Chougule 
//Course: CSS343
//Date: Feb 13, 2025

#include "graphm.h"
#include <iomanip>

//Constructor: initializes the graph
GraphM::GraphM(){
    size = 0;
    // Initialize adjacency matrix and  array
    for (int i = 1; i < MAXNODES_M; i++){
        for (int j = 1; j < MAXNODES_M; j++){
            C[i][j] = INT_MAX;
            T[i][j].visited = false;
            T[i][j].distance = INT_MAX;
            T[i][j].path = 0;
        }
    }
}

// Displays the shortest path from one node to another
void GraphM::display(int from, int to){
    if ((from > size || from < 0) || (to > size || to < 0)){
        cout << setw(7) << from << setw(7) << to;
        cout << setw(15) << "----" << endl;
        return;
    }

    cout << setw(7) << from << setw(7) << to;

    if (T[from][to].distance != INT_MAX){
        cout << setw(12) << T[from][to].distance << setw(15);
        findPath(from, to);
        cout << endl;
        findData(from, to);
    }
    else{
        cout << setw(15) << "----" << endl;
    }
    cout << endl;
}

// Recursively finds and displays path from one node to another
void GraphM::findPath(int from, int to){
    if (T[from][to].distance == INT_MAX){
        return;
    }

    if (from == to){
        cout << to << " ";
        return;
    }
    int pathData = to;
    findPath(from, to = T[from][to].path);
    cout << pathData << " ";
}


//Implements Dijkstra’s algorithm and finds shortest path
void GraphM::findShortestPath(){
    for (int source = 1; source <= size; source++){
        T[source][source].distance = 0;
        T[source][source].visited = true;
 
        //Initialize distances from the source
        for (int n = 1; n <= size; n++){
            if (C[source][n] != INT_MAX){
                T[source][n].distance = C[source][n];
                T[source][n].path = source;
            }
        }
        int v = 0;
        do{
            // Find the unvisited node with the shortest distance
            int min = INT_MAX;
            v = 0;

            for (int n = 1; n <= size; n++){
                if (!T[source][n].visited && (C[source][n] < min)){
                    min = C[source][n];
                    v = n;
                }
            }
            if (v == 0){
                break;
            }

            T[source][v].visited = true;

            // Update distances for neighboring nodes
            for (int w = 1; w <= size; ++w){
                if (T[source][w].visited){
                    continue;
                }

                if (C[v][w] == INT_MAX){
                    continue;
                }

                if (v == w){
                    continue;
                }

                if (T[source][w].distance > T[source][v].distance + C[v][w]){
                    T[source][w].distance = T[source][v].distance + C[v][w];
                    T[source][w].path = v;
                }
            }
        }
        while (v != 0);
    }
}

//Reading data from file and builds the graph 
int GraphM::buildGraph(ifstream& infile1){
    infile1 >> size; //reading the nodes
    string nodeName = "";
    getline(infile1, nodeName); 

    //reads node 
    for (int i = 1; i <= size; ++i){
        data[i].setData(infile1);
    }

    int from, to, dist;
    //reads edges and distances
    while (infile1 >> from >> to >> dist){
        if (from == 0){ //stops from == 0
            break;
        }
        C[from][to] = dist;
    }
    return 1;
}

// Inserts an edge between two nodes with a specified distance
bool GraphM::insertEdge(int from, int to, int dist){
    if (from > size || from < 1){
        return false;
    }

    if (to > size || to < 1){
        return false;
    }

    if (dist != 0 && from == to){
        return false;
    }

    if (dist < 0){
        return false;
    }

    C[from][to] = dist;
    findShortestPath();
    return true;
}

// Displays all shortest paths from all nodes
void GraphM::displayAll(){
    cout << "Description" << setw(20) << "From node" << setw(10) << "To node"
        << setw(14) << "Dijkstra's" << setw(7) << "Path" << endl;

    for (int from = 1; from <= size; from++){
        cout << data[from] << endl << endl;

        for (int to = 1; to <= size; to++){
            if (T[from][to].distance != 0){
                cout << setw(27) << from;
                cout << setw(10) << to;

                if (T[from][to].distance == INT_MAX){
                    cout << setw(12) << "----" << endl;
                }
                else{
                    cout << setw(12) << T[from][to].distance;
                    cout << setw(10);

                    findPath(from, to);
                    cout << endl;
                }
            }
        }
    }
}

// Recursively finds and displays the data along a path
void GraphM::findData(int from, int to){
    if (T[from][to].distance == INT_MAX){
        return;
    }

    if (from == to){
        cout << data[to] << endl;
        return;
    }

    int nodeData = to;
    findData(from, to = T[from][to].path);
    cout << data[nodeData] << endl << endl;
}

// Removes edge between two nodes
bool GraphM::removeEdge(int from, int to){
    if (from > size || from < 1){
        return false;
    }
    if (to > size || to < 1){
        return false;
    }

    C[from][to] = INT_MAX;
    findShortestPath();
    return true;
}
