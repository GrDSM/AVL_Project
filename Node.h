//
// Created by Dylon on 9/28/2023.
//

#ifndef AVL_PROJECT_NODE_H
#define AVL_PROJECT_NODE_H
#include <string>
using namespace std;


class Node
{

public:
    int value;
    string name;
    int height;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(string& _name, int& _value, int _height);
    void setLeft(Node* node);
    void setRight(Node* node);
};


#endif //AVL_PROJECT_NODE_H
