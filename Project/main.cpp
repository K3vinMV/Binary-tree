#include <iostream>
#include "Tree.h"
#include "Student.h"
#include "Node.h"

using namespace std;

void pause();

int main()
{
    Tree *tree=new Tree();
    Student data;
    int opt;
    string name;

    do
    {
        system("cls");
        cout<<"------------BINARY TREE------------"<<endl;
        cout<<"1.-Insert"<<endl;
        cout<<"2.-Inorder"<<endl;
        cout<<"3.-Preorder"<<endl;
        cout<<"4.-Postorder"<<endl;
        cout<<"5.-Search"<<endl;
        cout<<"6.-Minimum"<<endl;
        cout<<"7.-Maximum"<<endl;
        cout<<"8.-Height"<<endl;
        cout<<"9.-Size"<<endl;
        cout<<"10.-Remove"<<endl;
        cout<<"11.-Write"<<endl;
        cout<<"12.-Load"<<endl;
        cout<<"13.-Exit"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"Please enter an option: ";
        cin>>opt;

        switch(opt)
        {
        case 1:
            system("cls");
            cout<<"--------INSERT--------"<<endl;
            float score;
            int code;
            cout<<"Insert name: ";
            cin>>name;
            cout<<"\nInsert code: ";
            cin>>code;
            cout<<"\nInsert score: ";
            cin>>score;
            data.setname(name);
            data.setcode(code);
            data.setscore(score);
            tree->Insert(data,tree->root);
            pause();
            break;

        case 2:
            system("cls");
            cout<<"--------INORDER--------"<<endl;
            tree->inorder(tree->root);
            pause();
            break;

        case 3:
            system("cls");
            cout<<"--------PREORDER--------"<<endl;
            tree->preorder(tree->root);
            pause();
            break;

        case 4:
            system("cls");
            cout<<"--------POSTORDER--------"<<endl;
            tree->postorder(tree->root);
            pause();
            break;

        case 5:
            system("cls");
            Node *aux;
            int cd;
            cout<<"--------SEARCH--------"<<endl;
            cout<<"Please enter the code of the student you want to search: ";
            cin>>cd;
            aux=tree->Search(cd,tree->root);
            if(aux)
            {
                cout<<"\nThe student you are looking for is: "<<endl;
                cout<<aux->data.getname()<<endl;
                cout<<aux->data.getcode()<<endl;
                cout<<aux->data.getscore()<<endl;
            }else
            {
                cout<<"Tree is empty"<<endl;
            }
            pause();
            break;

        case 6:
            system("cls");
            Node *Min;
            cout<<"--------MINIMUM--------"<<endl;
            Min=tree->minimum(tree->root);
            if(Min)
            {
                cout<<"The student with the minimum score is:"<<endl;
                cout<<"Name: "<<Min->data.getname()<<endl;
                cout<<"Code: "<<Min->data.getcode()<<endl;
                cout<<"Score: "<<Min->data.getscore()<<endl;
            }else
            {
                cout<<"Tree is empty"<<endl;
            }
            pause();
            break;

        case 7:
            system("cls");
            Node *Max;
            cout<<"--------MAXIMUM--------"<<endl;
            Max=tree->maximum(tree->root);
            if(Max)
            {
                cout<<"The student with the maximum score is:"<<endl;
                cout<<"Name: "<<Max->data.getname()<<endl;
                cout<<"Code: "<<Max->data.getcode()<<endl;
                cout<<"Score: "<<Max->data.getscore()<<endl;
            }else
            {
                cout<<"Tree is empty"<<endl;
            }
            pause();
            break;

        case 8:
            system("cls");
            cout<<"--------HEIGHT--------"<<endl;
            int height;
            height=tree->height(tree->root);
            cout<<"The height of the tree is: "<<height<<endl;
            pause();
            break;

        case 9:
            system("cls");
            cout<<"--------SIZE--------"<<endl;
            int sz;
            sz=tree->Size(tree->root);
            cout<<"El tamano del arbol es: "<<sz<<endl;
            pause();
            break;

        case 10:
            system("cls");
            cout<<"--------REMOVE--------"<<endl;
            int codeRMV;
            Node *stud;
            cout<<"Enter the code of the student you want to remove: "<<endl;
            cin>>codeRMV;
            stud=tree->removeStud(tree->root,codeRMV);
            if(stud!=nullptr)
            {
                cout<<"Student removed"<<endl;
            }
            pause();
            break;

        case 11:
            system("cls");
            cout<<"--------WRITE--------"<<endl;
            tree->write(tree->root);
            cout<<"Saving changes..."<<endl;
            pause();
            break;

        case 12:
            system("cls");
            cout<<"--------LOAD--------"<<endl;
            tree->load();
            cout<<"Data loaded"<<endl;
            pause();
            break;

        case 13:
            system("cls");
            cout<<"Quitting..."<<endl;
            break;

        default:
            system("cls");
            cout<<"INVALID OPTION"<<endl;
            pause();
            break;
        }
    }while(opt!=13);

    return 0;
}

void pause()
{
    cout<<"Press any key to continue..."<<endl;
    getwchar();
    getwchar();
}
