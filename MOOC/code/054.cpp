/* 054:成绩排序 */
#include <bits/stdc++.h>
struct Student{
    char name[20];
    int score;
};
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int n;
    cin>>n;
    Student cla[n];
    for(int i=0;i<n;i++){
        cin>>cla[i].name;
        cin>>cla[i].score;
    }
    for(int i=0;i<n-1;i++){
        int p=i;
        for(int j=i+1;j<n;j++){
            if(cla[p].score<cla[j].score)
            p=j;
            else if(cla[p].score==cla[j].score && strcmp(cla[p].name,cla[j].name)>0)
            p=j;
        }
        Student temp = cla[p];
        cla[p] = cla[i];
        cla[i] = temp;
    }
    for(int i=0;i<n;i++){
        cout<<cla[i].name<<" ";
        cout<<cla[i].score<<endl;
    }
}

