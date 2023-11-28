#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int a,n,answer=1;
    cin>>a>>n;
    for(;n;n--){
        answer=answer*a;
    }
    cout<<answer;
}