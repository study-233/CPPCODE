/* P1089 [NOIP2004 提高组] 津津的储蓄计划 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int Budget[12];
    for(int i=0;i<12;i++){
        cin>>Budget[i];
    }
    int last=0;
    int money=0;
    int i=0;
    for(;i<12;i++){
        last+=300;
        if(last<Budget[i]){
            cout<<"-"<<i+1;
            break;
        }
        money+=(last-Budget[i])/100;
        last=(last-Budget[i])%100;
        
    }
    if(i==12) cout<<last+money*120;
}

