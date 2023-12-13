/*P1014 [NOIP1999 普及组] Cantor 表*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    int i=0;
    while(n>0){
        i++;
        n-=i;
    }
    n+=i;
    if(i%2==0) cout<<n<<"/"<<i+1-n;
    else cout<<i+1-n<<"/"<<n;
}

