//036:求最大公约数问题
#include <iostream>
#include <stdio.h>
using namespace std;
//用辗转相除法计算
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int a,b,temp;
    cin>>a>>b;
    while(a%b){
        temp=a%b;
        a=b;
        b=temp;
    }
    cout<<b;
}
