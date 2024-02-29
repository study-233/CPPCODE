/**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=10005;
int n;
int x,y,z;
ll X[10005],Y[10005],Z[10005],ans;

int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>X[i]>>Y[i]>>Z[i];
	}
	sort(X,X+n);sort(Y,Y+n);sort(Z,Z+n);
    x = X[n / 2];
    y = Y[n / 2];
    z = Z[n / 2];
    for(int i = 0 ; i < n ; ++i){
        ans += abs(x - X[i]) + abs(y - Y[i]) + abs(z - Z[i]);
    }
    cout<<ans;
    return 0;
}