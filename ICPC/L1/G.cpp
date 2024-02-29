#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
int fun(int n){
	int count=0,i=1;
	int cells[200];//0锁1开
	for(int i=1;i<n+1;i++){
		cells[i]=0;
	}	
	while(i<=n){
		int temp=i;
		while(temp<=n){
			cells[temp]=(cells[temp]+1)%2;
			temp+=i;
		}
		i++;
	}
	for(int i=1;i<n+1;i++){
		if(cells[i]==1) count++;
	}
	return count;
}
int main(){

    int N,n;
	cin>>N;	//Don't forget this!
	for(int i=0;i<N;i++){
		cin>>n;
		cout<<fun(n)<<endl;
	}
	
	
	return 0;
}