/* 052:指针练习：指向指针的指针 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
	int x,y,z;
	x = 10;
	y = 20;
	z = 30;
	
	int * a[3]  = { &x, &y,&z};
	for(int**p = a ;p < a + 3; ++p) 
			cout<< * (*p) << endl;
	return 0;
	
}