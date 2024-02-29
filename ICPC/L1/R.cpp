#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

	int n;
	while(cin>>n && n!=0){
		int count=0;
		while(n!=1){
			count++;
			if(n%2) n=(3*n+1)/2;
			else n/=2;
		}
		cout<<count<<endl;
	}
	
	
	
	return 0;
}