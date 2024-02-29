#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
int a[10];
int main(){

	int num;
	while(cin>>num){
		int i=0;
		
		while(num>0){
			a[i]=num%2;
			num/=2;
			i++;
		}
		
		if(a[i]==0) i--;
		
		while(i>=0){
			cout<<a[i];
			i--;
		}
		cout<<endl;
	}
	
	
	return 0;
}