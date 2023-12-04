#include <bits/stdc++.h>
using namespace std;
struct  Person  {
    char  name[20];
    long  id;
    float  salary;
};
Person  allone[6]={{"jone",12345,339.0},{"david",13916,449.0},{"marit",27519,311.0},
{"jasen",42876,623.0},{"peter",23987,400.0},{"yoke",12335,511.0}};
int  main()
{
    Person  *temp;
    int  i,j;
    Person*  index[6];
    for(int  p1=0;p1<5;p1++){
        int p = p1;
        for (int  j=p+1;j<6;j++){
            if(index[p]->salary > index[j]->salary) p=j;
        }
        temp = index[p];
        index[p] = index[j];
        index[j] = temp;
    }
    for(int  k=0;k<6;k++){
        cout  <<  index[k]->name  <<  "  "<<  index[k]->id  <<  "  "  <<  index[k]->salary  <<  endl;        
    }
    return  0;
}