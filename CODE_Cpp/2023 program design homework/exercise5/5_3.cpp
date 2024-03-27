/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
int fruit[100];

int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int T;
    int banana_num,tools_num;
    int ans=0,line=100;
    cin>>T;
    while(T--){
        cin>>banana_num>>tools_num;
        int bs[n+1];
        for(int i=1;i<=banana_num;i++) cin>>bs[i];
        if(tools_num >= banana_num){
            cout<<100<<endl;
            continue;
        }
        bs[0]=0;
        bs[banana_num+1]=line+1;
		int r=tools_num;
		line=1;//长度变成1 
		while(r<=banana_num)//控制m<=n
		{
			ans=max(ans,mp[r+1]-mp[line-1]+1-2);//因为要找最大的,所以用Max函数 
			line++;
			r++;
		}
		cout<<ans<<endl; 
    }


    return 0;
}
