#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){

	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int length;
		char dna[200];
		char rna[200];
		
		cin>>length;
		cin>>dna>>rna;
		int flag=1;
		for(int j=0;j<length && flag;j++){
			switch(dna[j]){
				case 'A' :if(rna[j]!='U') flag=0;break;
				case 'T' :if(rna[j]!='A') flag=0;break;
				case 'C' :if(rna[j]!='G') flag=0;break;
				case 'G' :if(rna[j]!='C') flag=0;break;			
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
	return 0;
}