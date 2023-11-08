#include <iostream>
#include <stdio.h>
using namespace std;
int a[4][4];
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            cin>>a[i][j];
        }
    }
    int flag=1;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(i>j){
                if(a[i][j]!=0) flag=0;
            }
            cin>>a[i][j];
        }
    }
    if(flag==1){
        cout<<"YES";
    }
    if(flag==0){
        cout<<"NO";
    }
    return 0;
}
