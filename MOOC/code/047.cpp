/* 047:指针练习：ForEach */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void ForEach(void * a, int width, int num,void (*f)(void*)){    //函数指针{
	for(int i = 0;i < num; ++i) 
		f((char*)a+width*i);
}
void PrintSquare(void * p)
{
	int * q = (int*)p;
	int n = *q;
	cout << n * n << ",";
}
void PrintChar(void * p) {
	char * q = (char*)p;
	cout << *q << ",";
}
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
	int a[5] = {1,2,3,4,5};
	char s[] = "hello!";
	ForEach(a,sizeof(int),5,PrintSquare); 
	cout << endl;
	ForEach(s,sizeof(char),6,PrintChar);
	return 0;
}

