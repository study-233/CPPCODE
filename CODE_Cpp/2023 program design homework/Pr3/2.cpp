/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Student{
public:
    Student(string name_) : name(name_),id(counter++) {}
    void printStuent(){
        cout<<id<<"-"<<name<<" ";
    }

    static int counter;
    int id;
    string name;
};
int Student::counter = 0; 

class Major{
public:
    Major(string name_):name(name_),id(counter++){}

    void printMajor(){
        cout << "Major " << id << "-" << name << ": ";
        for(auto student : students) {
            cout << student->id << "-" << student->name << " ";
        }
        cout << endl;
    }

    static int counter;
    int id;
    string name;
    vector<Student*> students;
};
int Major::counter = 0; 

int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    vector<Student*> students;
    vector<Major*> majors;
    string command, name;
    int preId;
    while (cin >> command) {
        if (command == "s") {
            cin >> name;
            students.push_back(new Student(name));
        } 
        else if (command == "m") {
            cin >> name;
            majors.push_back(new Major(name));
        }
        else if (command == "n") {
            for(auto Student : students)
                Student->printStuent();
        }
        else if (command == "l") {
            for(auto Major : majors)
                Major->printMajor();
        }
        else if (command == "a") {
            
        }

        else if (command == "d") {

        }
        else if (command == "v") {

        }
        else if (command == "e")
            break;
    }

    // Clean up dynamic allocation
    for(auto Student : students)
        delete Student;
    for(auto Major : majors)
        delete Major;   
    return 0;
}
