//Author: Anushka Chougule 
//Course: CSS343
//Date: Feb 13, 2025

#ifndef NODEDATA
#define NODEDATA

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class NodeData {
    friend ostream & operator<<(ostream &, const NodeData &);

public:
    //Construcotr + Destructor
    NodeData();
    ~NodeData();

    //Copy constructor + initialize w/string
    NodeData(const NodeData &);
    NodeData(const string &);
    
    //Assignment Operator  
    NodeData& operator=(const NodeData &);
    
    bool setData(istream&); //input stream data

    //Operator for comparison
    bool operator>(const NodeData &) const;
    bool operator<(const NodeData &) const;
    bool operator<=(const NodeData &) const;
    bool operator>=(const NodeData &) const;
    bool operator==(const NodeData &) const; 
    bool operator!=(const NodeData &) const;

private:
    string data;
};
#endif 
