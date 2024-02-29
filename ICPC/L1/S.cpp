#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

	int a,b;
	while(cin>>a>>b && !(a==0 && b==0)){
		int ans=1;
		a%=1000;
		while(b--){
			ans=ans*a%1000;
		}
		cout<<ans%1000<<endl;
	}
	
	
	
	return 0;
}