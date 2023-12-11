
/**/
#include <bits/stdc++.h>
using namespace std;
set<int> a={1,2,5};
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    set<int>::iterator p;
    p=a.upper_bound(2);
    cout<<*p;
    p=a.end();
    p--;
    cout<<*p;
    return 0;
}

