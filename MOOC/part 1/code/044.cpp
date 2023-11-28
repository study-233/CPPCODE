/* 044:密码翻译 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char str[80];
    cin.get(str,80);
    int i=0;
    while(str[i]){
        if(('a'<=str[i]&&str[i]<='z')||('A'<=str[i]&&str[i]<='Z')) cout<<(char)((str[i]+1-'a')%26+'a');
        else cout<<str[i];
        i++;
    }
}

