/* C */
#include <bits/stdc++.h>
using namespace std;
struct C{
    char name[50];
    int level;
};

int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    int n;
    cin>>n;
    C v[n];
    char f[50];
    for(int i=0;i<n;i++){
        cin>>v[i].name>>v[i].level;
    }

    strcpy(f,v[0].name);
    int max=v[0].level;

    for(int i=0;i<n;i++){
        if(v[i].level>=max){
            max=v[i].level;
            strcpy(f,v[i].name);
        }
    }

    cout<<f;
}
