#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

int a[101];
int main(){
    int i,n;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n/2+1;i++)
        sum+=a[i]/2+1;
    cout<<sum;
    return 0;

}