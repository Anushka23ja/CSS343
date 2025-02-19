//Author: Anushka Chougule 
//Course: CSS343
//Date: Feb 13, 2025

#include "graphl.h"
#include <iomanip>

//Constructor: initializes graph with given values 
GraphL::GraphL(){
    size = 0;
    for (int i = 1; i < MAXNODES_L; i++){
        node_array[i].visited = false;
        node_array[i].edgeHead = NULL;
        node_array[i].data = NULL;
    }
}

//Destructor: Ensures there is no memory leaks by cleaning allocated memory 
GraphL::~GraphL(){
    makeEmpty();
}

//Builds graph: Based on the input file like data31.txt, data32.txt and dataUWB.txt
int GraphL::buildGraph(ifstream& infile2){
    infile2 >> size;
    string nodeName = "";
    getline(infile2, nodeName);

    //Creating nodes from input files 
    for (int i = 1; i <= size; i++){
        getline(infile2, nodeName);
        NodeData* tmp = new NodeData(nodeName);
        node_array[i].data = tmp;
    }

    int from, to;

    //Creating edges between nodes 
    while (infile2 >> from >> to){
        if (from == 0){
            break;
        }

        if (node_array[from].edgeHead == NULL){
            EdgeNode* node = new EdgeNode;
            node->adjGraphNode = to;
            node_array[from].edgeHead = node;
            node_array[from].edgeHead->nextEdge  = NULL;
        }

        else{
            EdgeNode* node = new EdgeNode;
            node->adjGraphNode = to;
            node->nextEdge = node_array[from].edgeHead;
            node_array[from].edgeHead = node;
        }
    }
    return 1;
}

//DFS traversal is being performed on the graph  + visits all nodes that have not been visited
void GraphL::depthFirstSearch(){
    cout << "Depth-fisrt ordering:";
    for (int i = 1; i <= size; i++){
        if (!node_array[i].visited){
            depthFirstSearchHelper(i);
        }
    }
    cout << endl;
}

//Helper function for depthFirstSearch() by recursively visiting nodes 
void GraphL::depthFirstSearchHelper(int v){
    cout << setw(2) << v;
    node_array[v].visited = true;
    EdgeNode* curr = node_array[v].edgeHead;

    while (curr != NULL){
        if (!node_array[curr->adjGraphNode].visited){
            depthFirstSearchHelper(curr->adjGraphNode);
        }
        curr = curr->nextEdge;
    }
}

//Displays/prints the graph nodes + edges
void GraphL::displayGraph(){
    cout << "Graph:" << endl;

    for (int i = 1; i <= size; i++){
        cout << "Node" << i << "      " << *node_array[i].data << endl << endl;
        EdgeNode* curr = node_array[i].edgeHead;
        while (curr != NULL){
            cout << setw(7) << "edge " << i << setw(2) << curr->adjGraphNode << endl;
            curr = curr->nextEdge;
        }
    }
}

//Helper function: deletes all nodes + edges
void GraphL::makeEmpty(){
    for (int i = 1; i <= size; i++){
        node_array[i].visited = false;
        delete node_array[i].data;
        node_array[i].data = NULL;

        if (node_array[i].edgeHead != NULL){
            EdgeNode* deleteval = node_array[i].edgeHead;
            while (deleteval != NULL){
                node_array[i].edgeHead = node_array[i].edgeHead->nextEdge;
                delete deleteval;
                deleteval = NULL;
                deleteval = node_array[i].edgeHead;
            }
        }
    }
}
