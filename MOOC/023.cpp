#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int n,hour=0,max=0;
    int low,high;
    cin>>n;
    for(;n;n--){
        cin>>high>>low;
        if((low>=60&&low<=90)&&(high>=90&&high<=140)){
            hour++;
        }
        else{
            if(hour>max) max=hour;
            hour=0;
        }
    }
    if(hour>max) max=hour; // “判断最后一次”
    cout<<max;
    return 0;
}