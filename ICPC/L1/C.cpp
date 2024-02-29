#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){
	ll num;
	cin>>num;
	for(int i=0;i<num;i++){
		ll j=0;
		ll count=0;
	    char str[20];
	    cin>>str;
	    while(str[j]){
	    	switch(str[j]){
	    		case 'H' : count+=1;break;
	    		case 'C' : count+=12;break;
	    		default : count+=16;
	    	}
	    	j++;
	    }
	    cout<<count<<endl;
	}
	
	
	return 0;
}