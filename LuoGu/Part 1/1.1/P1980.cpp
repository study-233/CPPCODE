/*P1980 [NOIP2013 普及组] 计数问题*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n,x;
    int cnt=0;
    cin>>n>>x;
    while(n){
        int temp=n;
        while(temp){
            if(temp%10==x) cnt++;
            temp/=10;
        }
        n--;
    }
    cout<<cnt;
}

