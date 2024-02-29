#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

    int N;
    int a,b,c;
	cin>>N;	//Don't forget this!
	while(N--){
		cin>>a>>b>>c;
		int x=1000;
		while(x<=9999){
			if(x%a==0 && (x+1)%b==0 && (x+2)%c==0) break;
			x++;
		}
		if(x == 10000) cout<<"Impossible";
		else cout<<x;
		cout<<endl;
	}
	
	
	return 0;
}