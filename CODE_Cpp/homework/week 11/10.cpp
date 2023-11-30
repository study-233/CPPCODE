/* 10. 折半查找 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    int a[]={1, 3, 5, 7, 9, 11, 13, 15,17, 19};
    int l=0;
    int r=sizeof(a)/sizeof(int);
    int x;
    cin>>x;
    while (l<r){
        int k = (l+r)/2;
        if(a[k]==x){cout<<"yes";break;}
        else if(a[k]<x) r=k;
        else l=k;
    }
    if(l==r) cout<<"no";
}

