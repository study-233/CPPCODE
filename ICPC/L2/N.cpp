#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

    int N,k;
	cin>>N;	//Don't forget this!
	while(N--){
		cin>>k;
		int x=1;
		while(x<=1000){
			int temp=x;
			int count=0;
			while(temp){
				if(x%temp==0) count++;
				temp--;
			}
			if(count==k){
				cout<<x<<endl;
				break;
			}
			x++;
		}
		if(x>1000) cout<<-1<<endl;
	}
	
	
	return 0;
}