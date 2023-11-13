/* 041:找第一个只出现一次的字符 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char line[100000+10];
int count[1000];
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    cin.getline(line,sizeof(line));
    for(int i=0;line[i];i++){
        count[line[i]]++;
    }
    int j=0;
    for(;line[j];j++){
        if(count[line[j]]==1){
            cout<<line[j];
            break;
        }
    }
    if(line[j]==0) cout<<"no";
}