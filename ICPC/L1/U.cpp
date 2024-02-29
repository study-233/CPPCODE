#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
int num[32];
int main(){
	ll x;
    int T;
    cin>>T;
    while(T--){
    	cin>>x;
    	int i=0,ans=0;
    	memset(num,0,sizeof(num));
    	while(x){
    		num[i]=x%2;
    		x/=2;
    		i++;
    	}
    	int p=0;
    	while(p<i){
    		ans=ans*2+num[p];
    		p++;
    	}
    	cout<<ans<<endl;
    }
	
	
	return 0;
}