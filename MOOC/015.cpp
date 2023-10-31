#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    while(n&&y>0){
        n--;
        y-=x;
    }
    cout<<n;
}