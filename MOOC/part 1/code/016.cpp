#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int x,y;
    char f;
    cin>>x>>y>>f;
    if(!(f=='+'||f=='-'||f=='*'||f=='/'))
        cout<<"Invalid operator!";
    else{
        switch(f){
            case '+': cout<<x+y; break;
            case '-': cout<<x-y; break;
            case '*': cout<<x*y; break;
            case '/': 
            if(y) cout<<x/y;
            else cout<<"Divided by zero!";
        }

    }

}