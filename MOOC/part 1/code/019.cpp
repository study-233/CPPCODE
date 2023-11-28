#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int n,i,gold,silver,copper;
    int goldsum=0,silversum=0,coppersum=0;
    scanf("%d",&n); //输入天数
    for(i=n;i;i--){
        scanf("%d %d %d",&gold,&silver,&copper);
        goldsum+=gold;
        silversum+=silver;
        coppersum+=copper;
    }
    printf("%d %d %d %d",goldsum,silversum,coppersum,goldsum+silversum+coppersum); //输出
    return 0;

}