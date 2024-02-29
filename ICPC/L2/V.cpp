#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

    int T,n,ans;
	cin>>T;	//Don't forget this!
	while(T--){
		cin>>n;
		ans=pow(2,n)-1;
		cout<<ans<<endl;
	}
	
	
	return 0;
}