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
		if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a) cout<<"good";
		else if(a==b || b==c || a==c) cout<<"perfect";
		else cout<<"just a triangle";
		cout<<endl;
	}
	
	
	return 0;
}