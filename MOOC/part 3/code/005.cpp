#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
    private:
        string name;
        int age;
        int id;
        double s[4];
        double score;
    public:
        void input(){
            char str[100];
            cin.getline(str,100);
            const char * split = ",";
            char * p;
            p = strtok (str,split);
            name=p;
            p = strtok(NULL,split);
            age=atoi(p);
            p = strtok(NULL,split);
            id=atoi(p);
            p = strtok(NULL,split);
            for(int i=0;i<4;i++){
                s[i]=atoi(p);
                p = strtok(NULL,split);
            }
        }
        void calculate(){
            double temp=0;
            for(int i=0;i<4;i++){
                temp+=s[i];
            }
            score=temp/4;
        }
        void output(){
            cout<<name<<","<<age<<","<<id<<","<<score;
        }
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}