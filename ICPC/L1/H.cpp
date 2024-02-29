#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

    int N,n;
	cin>>N;	//Don't forget this!
	for(int i=0;i<N;i++){
		cin>>n;
		int count=0;
		while(n>0){
			if(n%2==1){
				count++;
				n--;
			}
			else n/=2;
		}
		cout<<count<<endl;
	}
	
	
	return 0;
}