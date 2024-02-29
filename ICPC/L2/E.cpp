#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

    int T,n;
	cin>>T;	//Don't forget this!
	while(T--){
		cin>>n;
		int x,min=100,max=-1;
		while(n--){
			cin>>x;
			if(min>x) min=x;
			if(max<x) max=x;
		}
		cout<<2*(max-min)<<endl;
	}
	
	
	return 0;
}