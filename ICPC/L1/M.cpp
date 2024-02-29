#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        int odd=0,even=0,m;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>m;
            if(m%2==0)
                even+=m/2;
            else{
                odd++;
                even+=(m-1)/2;
            }
        }
        if(odd==0)
            cout<<even*2;
        else{
            if(odd>even)
                cout<<1;
            else{
                int ans=even/odd;
                cout<<ans*2+1;
            }
        }
        cout<<endl;
    }
    return 0;

}