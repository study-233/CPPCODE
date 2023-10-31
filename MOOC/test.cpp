#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    unsigned int x = 0xffffffff;
    unsigned int b = x + 2;
    int y = x;
    printf("%x,%d,%x,%d",y,y,b,b);
}
