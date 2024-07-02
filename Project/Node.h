#ifndef NODE_H
#define NODE_H
#include "Student.h"
#include <iostream>

using namespace std;

class Node
{
    public:

        Node *left;
        Node *right;
        Student data;

        Node();
        Node(class Student, Node*, Node*);

};

#endif // NODE_H
