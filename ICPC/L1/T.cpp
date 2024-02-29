#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
int s[1000000]={0};
int main(){

    int n,i;
    int a[202];
    while(cin>>n &&n!=0)
    {
        memset(s,0,sizeof(s));
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s[a[i]]++;
        }
        for(i=0;i<n;i++)
        {
            if(s[a[i]]==1)
            {
               cout<<a[i]<<endl;
               break;
            }
        }
    }

	
	return 0;
}