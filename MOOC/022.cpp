#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    long int x;
    cin>>x;
    while(x!=1){
        if(x%2){
            cout<<x<<"*3+1=";
            x=x*3+1;
            cout<<x<<endl;
        }
        else{
            cout<<x<<"/2=";
            x=x/2;
            cout<<x<<endl;
        }
    }
    cout<<"End";
    return 0;
}