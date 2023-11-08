#include <iostream>
#include <stdio.h>
using namespace std;
int a[5][5];
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    //导入矩阵
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>a[i][j];
        }
    }
    //寻找鞍点
    int count=0; //是否找到
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int max=1;      //是否是最大值
            int min=1;      //是否是最小值
            //比较
            for(int p=0;p<5;p++){
                if(a[i][j]<a[i][p]) max=0;
            }
            for(int q=0;q<5;q++){
                if(a[i][j]>a[q][j]) min=0;
            }
            //是否是最大最小值
            if(max&&min){
                cout<<i+1<<" "<<j+1<<" "<<a[i][j];
                count++;
            }
        }
    }
    if(count==0) cout<<"not found";
}
