#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int N;
    double x1=0,x2=0,x3=0,x4=0;
    scanf("%d",&N);
    int age[N];
    for(int i=0;i<N;++i){
        scanf("%d",&age[i]);
    }
    for(int i=0;i<N;++i){
        if(age[i]<=18) x1++;
        else if(age[i]<=35) x2++;
        else if(age[i]<=60) x3++;
        else x4++;
    }
    printf("%.2f%\n%.2f%\n%.2f%\n%.2f%\n",x1/N*100,x2/N*100,x3/N*100,x4/N*100);
}
