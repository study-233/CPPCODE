#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

    int T;
	cin>>T;	//Don't forget this!
	for(int i=0;i<T;i++){
		int n;
		int day1=0,day2=0,day3=0;
		
		cin>>n;
		day1=1;
		for(int j=0;j<n-1;j++){
			day3=day2;
			day2=day1;
			day1=day2+day3;			
			day3=0;
		}
		cout<<day1+day2+day3<<endl;
	}

	return 0;
}