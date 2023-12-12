/*P1035 [NOIP2002 普及组] 级数求和*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    double sn=0;
    int k,n=1;
    cin>>k;
    while(sn<=k){
        sn+=1.0/n;
        n++;
    }
    cout<<n-1;

}

