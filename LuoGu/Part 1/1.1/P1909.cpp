/* P1909 [NOIP2016 普及组] 买铅笔 */
#include <bits/stdc++.h>
using namespace std;
int const N=1e5+5;
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

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
        if(price<min) min=price;
    }
    cout<<min;
}