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
    	int num,sheep=3;
    	cin>>num;
    	for(int j=0;j<num;j++){
    		sheep=(sheep-1)*2;
    	}
    	cout<<sheep<<endl;
    }
	

	
	return 0;
}