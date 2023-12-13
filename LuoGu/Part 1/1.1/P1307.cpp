/*P1307 [NOIP2011 普及组] 数字反转*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin>>n;
    int ans=0;
    while(n){
        ans=ans*10+n%10;
        n/=10;
    }
    cout<<ans;
}

