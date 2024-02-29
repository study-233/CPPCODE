#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
int list[25];
int main(){
	int c=1;
    int N;
	while(cin>>N && N!=0){	//Don't forget this!
		int count=-1;
		int flag=1;
		for(int i=0;i<N;i++){
			cin>>list[i];
		}
		while(flag && count<1000){
			
			flag=0;
			for(int i=0;i<N-1;i++){
				if(list[i]!=list[i+1]) flag=1;
			}
			
			int temp=list[0];
			for(int i=0;i<N-1;i++){
				list[i]=abs(list[i]-list[i+1]);
			}
			list[N-1]=abs(temp-list[N-1]);
			
			
			count++;
		}
		if(flag) cout<<"Case "<<c<<": not attained"<<endl;
		else cout<<"Case "<<c<<": "<<count<<" iterations"<<endl;
		c++;
	}
	return 0;
}