#include <iostream>
#include <string>
using namespace std;
class Document {
    protected:
        string Name;
    public:
        Document(string name) {
            Name = name;
        }
        virtual void PrintNameOf() {
            cout << "Name of book: " << Name << endl;
        }
};

class Book : public Document {
    private:
        long PageCount;
    public:
        Book(string name, long pageCount) : Document(name) {
            PageCount = pageCount;
        }

        void PrintNameOf() override {
            cout << "Name of book: " << Name <<" "<<PageCount<< endl;
        }
};

int main(){
    string name;
    long pageCount;
    Book myBook(name);
    myBook.PrintNameOf();
    return 0;
}