#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i,n,min,max,x;
    scanf("%d",&n);
    scanf("%d",&max);
    min=max; //初始化最大最小值
    for(i=n-1;i;i--){
        scanf("%d",&x);
        if(x>max) max=x; //判断数值
        if(x<min) min=x;
    }
    printf("%ld",max-min); //输出差
    return 0;

}