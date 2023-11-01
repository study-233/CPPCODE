#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int n=0,num=0,i,sum=0;
    scanf("%d",&n);
    for(i=n;i;i--){
        scanf("%d",&num);
        sum+=num;
        num=0;
    }
    printf("%ld %.5f",sum,double(sum/n));
    return 0;

}