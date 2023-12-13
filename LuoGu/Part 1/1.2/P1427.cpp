/*P1427 小鱼的数字游戏*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define int long long
    int a[100];
    int i=0;
    while(cin>>a[i] && a[i]!=0) i++;
    while(i){cout<<a[i-1]<<" ";i--;}
}

