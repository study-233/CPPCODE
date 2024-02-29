#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
int a[10];
int main(){

    int P;
	cin>>P;	//Don't forget this!
	while(P--){
		int x;
		cin>>x;
		for(int i=0;i<10;i++){
			cin>>a[i];
		}
		sort(a,a+10);
		cout<<x<<" "<<a[7]<<endl;
	}
	
	
	return 0;
}