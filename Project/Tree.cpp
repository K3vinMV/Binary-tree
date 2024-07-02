#include "Tree.h"
#include "Student.h"
#include "Node.h"
#include <fstream>
#include <sstream>


Tree::Tree()
{
    //ctor
}
Tree::Tree(Node*)
{
    root=nullptr;
}

void Tree::Insert(class Student data, Node *current)
{
    if(root==nullptr)
    {
        Node *tmp=new Node(data,nullptr,nullptr);
        root=tmp;
    }else
    {
        if(data.getscore()<current->data.getscore())
        {
            if(current->left==nullptr)
            {
                Node *tmp=new Node(data,nullptr,nullptr);
                current->left=tmp;
            }else
            {
                Insert(data,current->left);
            }
        }else
        {
          if(current->right==nullptr)
          {
              Node *tmp=new Node(data,nullptr,nullptr);
              current->right=tmp;
          }else
          {
              Insert(data,current->right);
          }
        }
    }
}

void Tree::inorder(Node *current)
{
    if(current)
    {
        inorder(current->left);
        cout<<"Name: "<<current->data.getname()<<endl;
        cout<<"Code: "<<current->data.getcode()<<endl;
        cout<<"Total score: "<<current->data.getscore()<<endl;
        cout<<"\n";
        inorder(current->right);
    }
}

void Tree::preorder(Node *current)
{
    if(current)
    {
        cout<<"Name: "<<current->data.getname()<<endl;
        cout<<"Code: "<<current->data.getcode()<<endl;
        cout<<"Total score: "<<current->data.getscore()<<endl;
        cout<<"\n";
        preorder(current->left);
        preorder(current->right);
    }
}

void Tree::postorder(Node *current)
{
    if(current)
    {
        postorder(current->left);
        postorder(current->right);
        cout<<"Name: "<<current->data.getname()<<endl;
        cout<<"Code: "<<current->data.getcode()<<endl;
        cout<<"Total score: "<<current->data.getscore()<<endl;
        cout<<"\n";
    }
}

Node* Tree::Search(int code, Node *current)
{
    if(current)
    {
        if(current->data.getcode()==code)
        {
            return current;
        }
        if(code<current->data.getcode())
        {
            return Search(code,current->left);
        }
        return Search(code,current->right);
    }else
    {
        return nullptr;
    }
}

Node* Tree::minimum(Node *current)
{
    if(current)
    {
        while(current->left)
        {
            current=current->left;
        }
        return current;
    }else
    {
        return nullptr;
    }
}

Node* Tree::maximum(Node *current)
{
    if(current)
    {
        while(current->right)
        {
            current=current->right;
        }
        return current;
    }else
    {
        return nullptr;
    }
}

int Tree::height(Node *current)
{
    if(current)
    {
        int height_lt = height(current->left);
        int height_rt = height(current->right);

        if(height_lt>height_rt)
        {
            return 1 + height_lt;
        }else
        {
            return 1 + height_rt;
        }
    }else
    {
        return 0;
    }
}

int Tree::Size(Node *current)
{
    if(current)
    {
        return 1 + Size(current->left) + Size(current->right);

    }else
    {
        return 0;
    }
}

Node* Tree::removeStud(Node *current, int code)
{
    if (current == nullptr)
    {
        cout<<"Student not found"<<endl;
    }
    else if (code < current->data.getcode())
    {
        current->left = removeStud(current->left, code);
    }
    else if (code > current->data.getcode())
    {
        current->right = removeStud(current->right, code);
    }
    else
    {
        if (current->left == nullptr)
        {
            Node* tmp = current->right;
            delete current;
            return tmp;

        } else if (current->right == nullptr)
        {
            Node* tmp = current->left;
            delete current;
            return tmp;
        }
        Node* tmp = minimum(current->right);
        current->data = tmp->data;
        current->right = removeStud(current->right, tmp->data.getcode());
    }
    return current;
}

void Tree::writeTree(Node *current, ofstream& file)
{
    if (current == nullptr)
    {
        return;
    }
    file<< current->data.getname() << '|' << current->data.getcode() << '|' << current->data.getscore() <<'*';
    writeTree(current->left, file);
    writeTree(current->right, file);
}

void Tree::write(Node *r)
{
    ofstream file( "file01.txt", ios::out );
    if(!file.is_open())
    {
    cerr << "The file can not be opened" << endl;
    exit( EXIT_FAILURE );
    }

    writeTree(r, file);
    file.close();
}

void Tree::load()
{
    ifstream file("file01.txt");

    if (!file.is_open())
    {
        cerr << "File can not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    string record;
    while (getline(file, record, '*'))
    {
        stringstream ss_reg(record);
        Student aux;

        string field;

        getline(ss_reg, field, '|');
        aux.setname(field);

        getline(ss_reg, field, '|');
        aux.setcode(stod(field));

        getline(ss_reg, field, '|');
        aux.setscore(stoi(field));

        Insert(aux,root);
    }

    file.close();
}
