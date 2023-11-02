#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i=1;
    while(1){
        if(i/7/7/7==0&&i/9/9/9==0){
            if((i%7==i/9/9)&&(i/7%7==i/9%9)&&(i/7/7==i%9)){
                cout<<i<<endl;
                cout<<i/7/7<<i/7%7<<i%7<<endl;
                cout<<i/9/9<<i/9%9<<i%9;
                break;
            }
            else
                i++;
        }
        else{
            i++;
        }
    }
}

