/* 043:最长最短单词 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int len;
    int j=0;
    int i=0;
    char word[300];
    //  存储最长的单词和最短单词的起始与结束位置
    int min_begin=0,min_end=200;
    int max_begin=0,max_end=0;
    cin.get(word,300);
    //  遍历寻找
    for(;word[i];i++){
        if(word[i]==' ' || word[i]==', '){
            if(i-j<min_end-min_begin){
                min_begin=j;
                min_end=i;
            }
            if(i-j>max_end-max_begin){
                max_begin=j;
                max_end=i;
            }
            j=i+1;
        }
    }
    //  判断最后一个单词
    if(i-j<min_end-min_begin){
        min_begin=j;
        min_end=i;
    }
    if(i-j>max_end-max_begin){
        max_begin=j;
        max_end=i;
    }
    //  输出
    for(int i=max_begin;i<max_end;i++) cout<<word[i];
    cout<<endl;
    for(int i=min_begin;i<min_end;i++) cout<<word[i];
}
