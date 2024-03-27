/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int m,n;
    cin>>m>>n;
    cout<<m<<n<<endl;
    char s;
    int i=0;
    while(cin>>s){
        cout<<s<<" ";
        if(i%n==0) cout<<endl;
        i++;
    }

    return 0;
}
