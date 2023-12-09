/*062:热血格斗场*/
#include <bits/stdc++.h>
using namespace std;
struct player{
    int id;
    int value;
};
struct Rule{
    bool operator() (const player & a1,const player & a2) const{
        return a1.value < a2.value;
    }
};
set<player,Rule> players={{1,1000000000}};
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin>>n;
    player newplayer;

    for(int i=0;i<n;i++){
        cin>>newplayer.id>>newplayer.value;
        set<player>::iterator p;
        p=players.upper_bound(newplayer);
        player op=*p;
        int df=abs(p->value-newplayer.value);
        if(p == players.end()) op=*p;
        else if (p != players.begin()){
            p--;
            int ndf=abs(p->value-newplayer.value);
            if(ndf<=df) op=*p;
        }
        cout<<newplayer.id<<" "<<op.id<<"\n";
        players.insert(newplayer);
    }
    return 0;
}

