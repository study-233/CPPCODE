/* 9. 数字组合 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    for(int i=0;i<9;i++){
        int a[]={1,2,3,4,5,6,7,8,9};
        cout<<a[i]<<" ";
        a[i]=0;
        for(int i=0;i<9;i++){
            if(a[i]){
                cout<<a[i];
                a[i]=0;
            }
            for(int i=0;i<9;i++){
                if(a[i]){
                    cout<<a[i];
                    a[i]=0;
                }
            }
        }
        cout<<endl;
    }
}

