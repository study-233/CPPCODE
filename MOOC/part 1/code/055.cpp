/* 055:分数线划定 */
#include <bits/stdc++.h>
using namespace std;
struct player{
    int num;
    int score;
};

int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    player a[m];
    for(int i=0;i<m;i++){
        cin>>a[i].num>>a[i].score;
    }
    //排序
    for(int i=0;i<m-1;i++){
        int p=i;
        for(int j=i+1;j<m;j++){
            if(a[p].score<a[j].score) p=j;
            else if(a[p].score==a[j].score && a[p].num>a[j].num){
            p=j;
            }   
        }
        player temp = a[p];
        a[p] = a[i];
        a[i] = temp;
    }
    int p = ((double)n*1.5);
    while(a[p-1].score==a[p].score) {p++;}  //判断是否有重复的
    cout<<a[p-1].score<<" "<<p<<endl;
    //输出
    for(int i=0;i<p;i++){
        cout<<a[i].num<<" "<<a[i].score<<endl;
    }   
}
