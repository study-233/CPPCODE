#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int a,N,x,count=0;
    cin>>N;
    int num[N];
    for(int i=0;i<N;++i){
        cin>>x;
        num[i]=x;
    }
    for(int i=0;i<N;++i){
        cin>>a;
        if(num[i]==a) count++;
    }
    cout<<count;
}
