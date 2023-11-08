#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int b[m][n];
    //存储矩阵
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    //转置矩阵
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b[j][i]=a[i][j];
        }
    }
    //输出矩阵
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
            if(j==n-1) cout<<endl;
        }
    }
}
