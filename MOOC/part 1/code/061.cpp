/* 061:Set */
#include <bits/stdc++.h>
using namespace std;
multiset<int> st;
set<int> s;
void add(int x){
    st.insert(x);
    s.insert(x);
    cout<<st.count(x);
}
void del(int x){
    cout<<st.count(x);
    st.erase(x);
}
void ask(int x){
    if(s.find(x)==s.end()) cout<<0;
    else cout<<1;
    cout<<" ";
    cout<<st.count(x);

}

int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n,x;
    string str;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str>>x;
        if(str=="add") add(x);
        else if(str=="del") del(x);
        else ask(x);
        cout<<"\n";
    }
    return 0;
}
