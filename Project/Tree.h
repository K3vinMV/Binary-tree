#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree
{
    public:
        Node *root;
        Tree();
        Tree(Node*);

        void Insert(class Student, Node*);
        void inorder(Node*);
        void preorder(Node*);
        void postorder(Node*);
        Node* Search(int, Node*);
        Node* minimum(Node*);
        Node* maximum(Node*);
        int height(Node*);
        int Size(Node*);
        Node* removeStud(Node*, int);
        void writeTree(Node*, ofstream&);
        void write(Node*);
        void load();

};

#endif // TREE_H
