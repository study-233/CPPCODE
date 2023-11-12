#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int L,R,i,p,count=0;
    cin>>L>>R;
    i=L;
    while(i<=R){
        p=i;
        while(p){
            if(p%10==2) count++;
            p/=10;
        }
        i++;
    }
    cout<<count;
}