#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
char ciphertext[100];
int ciphercode[100];
int plaincode[100];
int main(){

	int key;
	while(cin>>key && key!=0){
		int n=0;
		cin>>ciphertext;
		for(;ciphertext[n];n++){
			if(ciphertext[n]=='_') ciphercode[n]=0;
			else if(ciphertext[n]=='.') ciphercode[n]=27;
			else ciphercode[n]=ciphertext[n]-'a'+1;
		}
		plaincode[0]=ciphercode[0];
		for(int j=1;j<n;j++)
			plaincode[key*j % n] = (j + ciphercode[j])%28;
		for(int j=0;j<n;j++){		
			if(plaincode[j]==0) cout<<'_';
			else if(plaincode[j]==27) cout<<'.';
			else cout<<char((plaincode[j]-1)%26+'a');		
		}
		cout<<endl;
	}
	
	
	return 0;
}