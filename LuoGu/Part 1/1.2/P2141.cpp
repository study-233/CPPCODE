/*P2141 [NOIP2014 普及组] 珠心算测验*/
#include <bits/stdc++.h>
using namespace std;
int const N=1e+6;
int sum[N];
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp=a[i]+a[j];
            sum[temp]=1;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(sum[a[i]]==1) cnt++;
    }
    cout<<cnt;
}

