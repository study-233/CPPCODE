#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int n,num=0;
    double sum=0;
    scanf("%d",&n);
    for(;n;n--){
        scanf("%d",&num);
        sum+=num;
        num=0;
    }
    printf("%d %.5f",sum,sum/n);
    return 0;

}