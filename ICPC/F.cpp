/**/
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    long long n,m;
    cin>>n>>m;
    int a[n+1]={};
    int b[n+1];
    int x;
    for(int i=0;i<m;i++){
        cin>>x;
        a[x]++;
        cin>>x;
        a[x]++;        
    }
    int j=0;
    for(int i=1;i<n+1;i++){
        if(a[i]==1){
            b[j]=i;
            j++;
        }
    }
    cout<<j<<endl;
    for(int i=0;i<j;i++){
        cout<<b[i]<<" ";
    }
}

