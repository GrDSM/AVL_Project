//
// Created by Dylon on 9/28/2023.
//

#include "Node.h"

Node::Node(string &_name, int &_value, int _height)
{
    name = _name;
    value = _value;
    height = _height;
}

void Node::setLeft(Node *node)
{
    left = node;
}

void Node::setRight(Node *node)
{
    right = node;
}
