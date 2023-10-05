//
// Created by Dylon on 9/28/2023.
//

#include "Node.h"

//constructs the Node class
//sets the name, value, and height variables to the inserted items
Node::Node(string &_name, int &_value, int _height)
{
    name = _name;
    value = _value;
    height = _height;
}


//finds and returns the difference between the node's left and right's heights
int Node::findBalance(Node* node)
{
    //initializes the leftHeight and rightHeight variables
    int leftHeight = 0;
    int rightHeight = 0;

    //checks if the node's left is not a nullptr and then makes the leftHeight's value left's height
    //if left is a nullptr it keeps it as 0
    if (node->left != nullptr)
    {
        leftHeight = node->left->height;
    }

    //checks if the node's right is not a nullptr and then makes the rightHeight's value right's height
    //if right is a nullptr it keeps it as 0
    if (node->right != nullptr)
    {
        rightHeight = node->right->height;
    }

    //return's the difference of leftHeight and rightHeight
    return leftHeight - rightHeight;
}