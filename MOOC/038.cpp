//038:编程填空：第i位取反
#include <iostream>
#include <stdio.h>
using namespace std;

int bitManipulation1(int n, int i) {
return ((~(1<<i))&n)^n;
}

int main() {
    freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
	int n, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> i;
		cout << bitManipulation1(n, i) << endl;
	}
	return 0;
}