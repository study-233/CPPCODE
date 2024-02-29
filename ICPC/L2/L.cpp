#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

    int n;
    while(cin>>n && n!=0){
    	int a[100];
    	for(int i=0;i<n;i++){
    		cin>>a[i];
    	}
    	sort(a,a+n);
    	int sum=0;
    	for(int i=1;i<n-1;i++){
    		sum+=a[i];
    	}
    	sum/=n-2;
    	cout<<sum<<endl;
    }
	
	
	return 0;
}