#include "date.h"
#include <iostream>
using namespace std;
int year,month,day;
int main(){
    try{
        cin>>year>>month>>day;
        Date date(year,month,day);
        date.show();
    }
    catch (DateException& e){
        cout<<e.what()<<endl;
    }
    system("pause");
}