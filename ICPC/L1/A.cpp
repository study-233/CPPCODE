#include <iostream>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

void Change(int x){
	static int count=1;
	int q=0,d=0,n=0,a=0;
	while(x>=25){
		x-=25;
		q++;
	}
	while(x>=10){
		x-=10;
		d++;
	}
	while(x>=5){
		x-=5;
		n++;
	}
	a=x;
	cout<<count<<" ";
	cout<<q<<" QUARTER(S), ";
	cout<<d<<" DIME(S), ";
	cout<<n<<" NICKEL(S), ";
	cout<<a<<" PENNY(S) "<<endl;
	count++;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    
    int N,x;
	cin>>N;	//Don't forget this!
	while(N){
		cin>>x;
		Change(x);
		N--;
	}
	return 0;
}