/*P1085 [NOIP2004 普及组] 不高兴的津津*/
#include <bits/stdc++.h>
using namespace std;
int times[7];
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int x,y;
    for(int i=0;i<7;i++){
        cin>>x>>y;
        times[i]=x+y;
    }
    int max=times[0];
    int j=0;
    for(int i=0;i<7;i++){
        if(times[i]>max && times[i]>8){
            max=times[i];
            j=i+1;
        }
    }
    cout<<j;    
        
}

