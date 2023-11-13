/*  040:统计数字字符个数  */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char line[300];
    int count=0;
    cin.getline(line,sizeof(line));
    for(int i=0;line[i];i++){
        if('0'<=line[i] && line[i]<='9')
            count++;
    }
    cout<<count;
}