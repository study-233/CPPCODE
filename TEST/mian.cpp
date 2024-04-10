#include <iostream>
using namespace std;

class MyException : public std::exception {
private:
    string _msg;

public:
    MyException(string msg) : _msg(msg) {}

    const char* what() const noexcept override {
        static string s="错误:"+_msg;
        return s.c_str();
    }
};

void foo(int x) {
    if (x < 0) {
        throw MyException("x不能为负数");
    }
}

int main(){
    try {
        foo(-1);
    } 
    catch (MyException& e) {
        cout << e.what() << endl;
    }
    return 0;

}

