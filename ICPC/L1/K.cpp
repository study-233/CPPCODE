#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
ll a[100];
int main(){
	a[1]=1;
	a[2]=3;
	for(int i=3;i<50;i++){
		a[i]=a[i-1]+2*a[i-2];
	}
	int C,n;
	cin>>C;
	for(int i=0;i<C;i++){
		cin>>n;
		cout<<a[n]<<endl;
	}
	
	
	return 0;
}