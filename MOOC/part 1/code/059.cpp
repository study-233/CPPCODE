/* 059:sort简单题 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);

	int a[8] = {6,5,14,23,2,9,87,10 };
	sort(a+1,a+7,greater<int>());
	for(int i = 0;i < 8; ++i)
		cout << a[i] << "," ; 
	return 0;

}
