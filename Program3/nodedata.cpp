//Author: Anushka Chougule 
//Course: CSS343
//Date: Feb 13, 2025

#include "nodedata.h"

// Default constructor + Destructor
NodeData::NodeData() { data = ""; }
NodeData::~NodeData() { }

// Copy constructor
NodeData::NodeData(const NodeData& nd){ 
    data = nd.data; 
}

// Constructor with string parameter
NodeData::NodeData(const string& s){ 
    data = s; 
}

// Assignment operator: checks for self-assignment and copies data
NodeData& NodeData::operator=(const NodeData& rhs){
    if (this != &rhs){
        data = rhs.data;
    }
    return *this;
}

//Operator: Returns true if data matches
bool NodeData::operator==(const NodeData& rhs)const{
    return data == rhs.data;
}

// Less-than operator: compares data
bool NodeData::operator<(const NodeData& rhs)const{
    return data < rhs.data;
}

// Greater-than operator: compares data 
bool NodeData::operator>(const NodeData& rhs)const {
    return data > rhs.data;
}

// Prints data to the output stream
ostream& operator<<(ostream& output, const NodeData& nd){
    output << nd.data;
    return output;
}

// Less-than-or-equal and Greater-than-or-equal operator
bool NodeData::operator<=(const NodeData& rhs)const{
    return data <= rhs.data;
}

bool NodeData::operator>=(const NodeData& rhs)const{
    return data >= rhs.data;
}

// Reads data from an input stream and stores it
bool NodeData::setData(istream& infile){
    getline(infile, data);
    return !infile.eof();
}

// Not-equal operator: returns true if data does not match
bool NodeData::operator!=(const NodeData& rhs)const{
    return data != rhs.data;
}