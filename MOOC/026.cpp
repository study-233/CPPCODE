#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    long int M,m=0,N,X;
    cin>>M>>N>>X;
    while(X){
        while((m<M)&&X){
            m+=N;
            X--;
        }
        if(m>=M){
            N+=M/N;
            m=0;
        }
    }
    cout<<N;
}