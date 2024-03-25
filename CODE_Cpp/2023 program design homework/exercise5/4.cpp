/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int aim_lights[5][6]={0};
int PUZZLE[5][6]={0};

void read(){
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            cin>>aim_lights[i][j];
        }
    }
}
void change(int i,int j){
    if(i>=0 && i<=4 && j>=0 && j<=5)
        aim_lights[i][j] = (aim_lights[i][j]+1) % 2;
}
void solve(){
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            if(aim_lights[i][j]==1){
                change(i,j);
                change(i+1,j);
                change(i,j+1);
                change(i-1,j);
                change(i,j-1);
                PUZZLE[i][j]=1;
            }
        }
    }    
}
void print_PUZZLE(){
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            cout<<PUZZLE[i][j]<<" ";
        }
        cout<<endl;
    }    
}
int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        read();
        solve();
        cout<<"PUZZLE #"<<i<<endl;
        print_PUZZLE();

    }
    return 0;
}
