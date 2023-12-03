/* 056:病人排队 */
#include <bits/stdc++.h>
using namespace std;
struct inf{
    char ID[10];
    int age;
    int order;
};
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    int num;
    cin>>num;
    inf patient[num];
    for(int i=0;i<num;i++){
        cin>>patient[i].ID>>patient[i].age;
        patient[i].order=i;
    }
    for(int i=0;i<num-1;i++){
        int p=i;
        for(int j=i+1;j<num;j++){
            if(patient[p].age>=60 && patient[j].age>=60){
                if(patient[p].age < patient[j].age) p=j;
                else if(patient[p].age == patient[j].age){
                    if(patient[p].order > patient[j].order) p=j;
                }
            }
            else if(patient[p].age<60 && patient[j].age<60){
                if(patient[p].order > patient[j].order) p=j;
            }
            else{
                if(patient[j].age>=60) p=j;
            }
        }
        inf temp = patient[p];
        patient[p] = patient[i];
        patient[i] = temp;
    }
    for(int i=0;i<num;i++){
        cout<<patient[i].ID<<endl;
    }
}

/*

1, a>=60 b>=60 排年龄 再排ID
2，a<=60 b<=60 排ID
3，排年龄

*/