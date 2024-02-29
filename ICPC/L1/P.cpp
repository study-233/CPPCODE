#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){
	int t,n,a[105],all,num;
    cin>>t;
    while(t--){
        cin>>n;
        all=0;
        for(int i=1;i<n;i++){
            cin>>a[i];
            all+=a[i];
        }
        int l=0,r=all*2,mid=-1;
        while(1){
            if((l+r)/2==mid) break;
            mid=(l+r)/2;
            if(mid>((mid+all)*2/3/n)) r=mid;
            else l=mid;
        }
        num=1;
        for(int i=1;i<n;i++)
            if(l==a[i]) num++;
        	cout<<l<<" ";
        	cout<<fixed<<setprecision(2)<<(1.0)/num<<endl;

		}
	return 0;
}