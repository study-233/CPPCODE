#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int h[10];
    int maxh,count=0;
    for(int i=0;i<10;++i){
        cin>>h[i];
    }
    cin>>maxh;
    for(int i=0;i<10;++i){
        if(maxh+30>=h[i]) count++;
    }
    cout<<count;
}
