#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int x,newx=0;
    cin>>x;
    while(x){
        newx=newx*10+x%10;
        x=x/10;
    }
    cout<<newx;
}