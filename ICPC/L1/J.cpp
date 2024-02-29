#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

	int n,u,d;
	while(cin>>n){
		if(n==0) break;
		cin>>u>>d;
		int h=0,time=0;
		while(h<n){
			h+=u;
			time++;
			if(h>=n) break;
			else{
				h-=d;
				time++;
			}
		}
		cout<<time<<endl;
	}
	
	
	
	return 0;
}