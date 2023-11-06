#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int a[4][4];
    int x1[4][4]={{1,1,1,1},{0,1,1,1},{0,0,1,1},{0,0,0,1}};
    int x2[4][4]={{1,1,1,1},{1,1,1,0},{1,1,0,0},{1,0,0,0}};
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            cin>>a[i][j];
        }
    }
    if(a==x1||a==x2) cout<<"YES";
    else cout<<"NO";
    
}
