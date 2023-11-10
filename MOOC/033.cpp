//033:图像模糊处理
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    //存储像素点灰度值
    int n,m;
    cin>>n>>m;
    int a[n][m];    //原灰度值
    int b[n][m];    //新灰度值
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    //处理灰度值
        //四周灰度值不变
    for(int j=0;j<m;j++){
        b[0][j]=a[0][j];
        b[n-1][j]=a[n-1][j];
    }
    for(int i=0;i<n;i++){
        b[i][0]=a[i][0];
        b[i][m-1]=a[i][m-1];
    }
        //处理中间灰度值
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            double temp;
            temp=(double)(a[i][j]+a[i-1][j]+a[i][j-1]+a[i+1][j]+a[i][j+1])/5;
            b[i][j]=(int)(temp+0.5);    //四舍五入
        }
    }

    //输出新灰度值
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<b[i][j]<<" ";
            if(j==m-1) cout<<endl;
        }
    }
}
