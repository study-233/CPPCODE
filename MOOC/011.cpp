#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
int h,r,count;
double Pi;
Pi=3.14159;
cin>>h>>r;
count=20000/(Pi*r*r*h)+1;
cout<<count;

}