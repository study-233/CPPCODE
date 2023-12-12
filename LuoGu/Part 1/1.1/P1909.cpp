/* P1909 [NOIP2016 普及组] 买铅笔 */
#include <bits/stdc++.h>
using namespace std;
int const N=1e5+5;
set<int> st;
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    set<int>::iterator p;
    int need;
    int num,pr,price;
    cin>>need;
    int min=N;
    for(int i=0;i<3;i++){
        cin>>num>>pr;
        price=0;
        int temp=need;
        while(temp>0){
            temp-=num;
            price+=pr;
        }
        st.insert(price);
    }
    p=st.begin();
    cout<<*p;
}