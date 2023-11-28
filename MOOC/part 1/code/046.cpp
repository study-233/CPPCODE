/* 046:指针练习:输出Tesla */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void Print(const char * p1, const char * p2) {  
	for(;p1<p2;p1++) 
    cout<<*p1;
}
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    const char * s = "Tesla123";
	Print(s,s+5);
	cout << endl;
	Print(s,s+3);
	cout << endl;
	return 0;
}

