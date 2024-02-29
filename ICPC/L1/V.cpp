#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
ll a[50]={0};
int main(){
	a[0]=2;
	a[1]=3;
	int i=2;
	while(1){
		a[i]=a[i-1]+a[i-2];
		if(a[i]>2147483648) break;
		i++;
	}
	ll n;
	int flag=0;
	while(cin>>n && n!=0){
		for(int i=0;i<50;i++){
			if(a[i]==n) break;
			else if(a[i]>n){
				flag=1;
				break;
			}
		}
		if(flag) cout<<"First win"<<endl;
		else cout<<"Second win"<<endl;
	}
	
	
	return 0;
}