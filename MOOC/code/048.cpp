/* 048:指针练习：Memcpy之一 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
//  复制 *src 的值到 *dest
void Memcpy(char * src ,char * dest,int n){
while(n){
    *dest=*src;
    src++;
    dest++;
    n--;
}
}
//  返回字符串长度
int Strlen(char * s)
{	
	int i;
	for( i = 0; s[i]; ++i);
	return i;
}

int main(){
    freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int a;
	char s1[30];
	char s2[30];
	int t;
	cin >> t;
	for(int i = 0;i < t; ++i) {
		cin >> a;
		int b = 99999999;
		Memcpy((char*)&a,(char *) &b,sizeof(int));
		cout << b << endl;
	}
	for(int i = 0;i < t; ++i) {
		cin >> s1;
		Memcpy(s1,s2,Strlen(s1)+1);
		cout << s2 << endl;
	}
	return 0;
}

