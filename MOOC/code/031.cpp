#include <iostream>
#include <stdio.h>
using namespace std;
int a[100000];
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int L,M,sum=0;
    cin>>L>>M;
    for(int i=0;i<L+1;i++){
        a[i]=1;
    }
    while(M){
        int start=0,end=0;
        cin>>start>>end;
        for(int i=start;i<end+1;i++){
            a[i]=0;
        }
        M--;
    }
    for(int i=0;i<L+1;i++){
        if(a[i]) sum++;
    }
    cout<<sum;
}
