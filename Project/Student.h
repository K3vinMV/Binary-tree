#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
    public:
        void setname(string nm)
        {
            name=nm;
        }
        string getname()
        {
            return name;
        }
        void setscore(float scr)
        {
            score=scr;
        }
        float getscore()
        {
            return score;
        }
        void setcode(int cd)
        {
            code=cd;
        }
        int getcode()
        {
            return code;
        }
        Student();

    private:
        string name;
        float score;
        int code;
};

#endif // STUDENT_H
