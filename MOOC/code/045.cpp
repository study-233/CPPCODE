/* 045:指针练习：输出Hello */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    char s[] = "Hello";  
	char * p;
	for(p=s;*p;++p)
		cout << * p ;
	return 0;
}


