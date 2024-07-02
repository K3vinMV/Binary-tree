#include "Node.h"

Node::Node()
{
    left=nullptr;
    right=nullptr;
    //ctor
}

Node::Node(class Student data, Node *left, Node *right)
{
    this->data=data;
    this->left=left;
    this->right=right;
}
