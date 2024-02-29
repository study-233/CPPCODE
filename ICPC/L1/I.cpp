#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

	int n;
	while(cin>>n){
		int temp=1;
		for(int i=0;i<n-1;i++){
			temp=(temp+1)*2;
		}
		cout<<temp<<endl;
	}
	
	return 0;
}