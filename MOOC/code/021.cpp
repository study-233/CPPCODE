#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int n;
    double x,total,youxiao;
    string out="";
    cin>>n;
    cin>>total>>youxiao;
    x=youxiao/total; //鸡尾酒疗法计算
    for(;n>1;n--){
        cin>>total>>youxiao;
        if((youxiao/total-x)>0.05){ // #if语句判断
            out+="better\n"; //储存结果
        }
        else if((x-youxiao/total)>0.05){
            out+="worse\n";
        }
        else{
            out+="same\n";
        }
    }
    cout<<out;
}