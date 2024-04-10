//student.h
#ifndef _STUDENT_H     //防止重复包含和编译
#define _STUDENT_H
#include <string>
using namespace std;
class Student{
    private:
        int id;
        string name;
    public:
        Student(int id_,string name_);
        void getid() const{ return id; }
}
#endif
