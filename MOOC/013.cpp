#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
    double a,b,c,d,x1,x2,jp,ip;
    scanf("%lf%lf%lf",&a,&b,&c);
    d=b*b-4*a*c; //计算判别式
    if(d==0){  //判断并输出
        x1 = -b/(2*a);
        printf("x1=x2=%.5f",x1);
    }
    if(d>0){
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
        printf("x1=%.5f;x2=%.5f",x1,x2);
    }
    if(d<0){
        jp = -b/(2*a);
        ip = sqrt(-d)/(2*a);
        printf("x1=%.5f+%.5fi;",jp,ip);
        printf("x1=%.5f-%.5fi",jp,ip);
    }

}
