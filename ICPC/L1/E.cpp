#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int s,c;
		cin>>s>>c;
		if(s>c) cout<<s*2+c<<endl;
		else cout<<c*2+s<<endl;
	}
	
	
	return 0;
}