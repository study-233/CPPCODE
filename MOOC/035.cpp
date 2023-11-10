#include <iostream>
#include <stdio.h>
using namespace std;

int a[999999+1000]={0,1,2}; // 存储数列a各项数取模后的值

int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    int n, x; 
	for(int i = 3; i <= 1000000; ++i)
		a[i] = (2*a[i-1] + a[i-2])%32767;       //计算数列a各项数取模后的值
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> x;
		cout << a[x] << endl;
	}
	return 0;
}
