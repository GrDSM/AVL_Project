//
// Created by Dylon on 9/28/2023.
//

#ifndef AVL_PROJECT_NODE_H
#define AVL_PROJECT_NODE_H
#include <string>
using namespace std;

//
class Node
{
    //initializes the value (aka the student's ID), name, and height variables
    int value;
    string name;
    int height;

    //initializes the left and right nodes and automatically makes them nullptrs
    Node* left = nullptr;
    Node* right = nullptr;

    //creates the constructor method
    Node(string& _name, int& _value, int _height);
public:
    int findBalance(Node* node);

};


#endif //AVL_PROJECT_NODE_H
