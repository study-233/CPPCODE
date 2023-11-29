/* 4. 荷兰国旗问题 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    char inStr[256];
    char* str[100];
    int p=0;
    cin.getline(inStr,256);
    str[p] = strtok (inStr," ");
    while(str[p] != NULL){
        p++;
        str[p] = strtok (NULL," ");
    }

    for(int i=0;i<p;i++){
        cout<<str[i]<<" ";
    }
}
