#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
int a[6];
int main(){

    int T;
	cin>>T;	//Don't forget this!
	while(T--){
		for(int i=0;i<6;i++){
			cin>>a[i];	
		}
		sort(a,a+6);
		int Shawn=a[4]+a[5];
		int Mzry=a[1]+a[2]+a[3];
		if(Shawn>Mzry) cout<<"Grandpa Shawn is the Winner!"<<endl;
		else cout<<"What a sad story!"<<endl;
	}
	
	
	return 0;
}