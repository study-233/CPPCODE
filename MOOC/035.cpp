#include <iostream>
#include <stdio.h>
using namespace std;
//用递归 求Pell数列第k项
int Pell(int k){
    if(a[k]!=0) return a[k];
    a[k]=(2*Pell(k-1)+Pell(k-2))%32767;
    return a[k];
}
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        cout<<Pell(x)<<endl;
    }
    return 0;
}
