/* 053:指针练习：SwapMemory */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void SwapMemory(void * m1,void * m2, int size){
    char* p1 = (char*) m1;
    char* p2 = (char*) m2;
    while(size){
        char temp = *p1 ;
        *p1 = *p2 ;
        *p2 = temp ; 
        ++p1;
        ++p2;
        size--;
    }
}

void PrintIntArray(int * a,int n){
	for(int i = 0;i < n; ++i)
		cout << a[i] << ",";
	cout << endl;
}
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int a[5] = {1,2,3,4,5};
	int b[5] = {10,20,30,40,50};
	SwapMemory(a,b,5 * sizeof(int));
	PrintIntArray(a,5);
	PrintIntArray(b,5);
	char s1[] = "12345";
	char s2[] = "abcde";
	SwapMemory(s1,s2,5);
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}