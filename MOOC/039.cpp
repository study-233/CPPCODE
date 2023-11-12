//039:编程填空：左边i位取反
#include <iostream>
#include <stdio.h>
using namespace std;

int bitManipulation3(int n, int i) {
return (((-1>>i))^n);
}

int main() {
    freopen("E:\\Codefield\\cppcode\\MOOC\\in.txt","r",stdin);
	int n, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}