/* Reina with a new function */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    int t;
    long long n,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        int count=1;
        if(k==1){
            cout<<"Impossible"<<endl;
        }
        else{
            while(n){
                if(n%k==0){
                    n/=k;
                    count++;
                }
                else{
                    count+=n%k;
                    n -= n%k;
                }
                
            }
            cout<<count<<endl;
        }
    }
}

