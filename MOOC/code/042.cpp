/* 042:石头剪子布 */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char player1[10];
char player2[10];

int main(){
    //freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
    int n;
    cin>>n;
    while(n--){
        cin>>player1;
        cin>>player2;
        if(!strcmp(player1,"Rock")){
            if(!strcmp(player2,"Rock")) cout<<"Tie";
            else if(!strcmp(player2,"Scissors")) cout<<"Player1";
            else cout<<"Player2";
        }
        else if(!strcmp(player1,"Scissors")){
            if(!strcmp(player2,"Scissors")) cout<<"Tie";
            else if(!strcmp(player2,"Paper")) cout<<"Player1";
            else cout<<"Player2";            
        }
        else{
            if(!strcmp(player2,"Paper")) cout<<"Tie";
            else if(!strcmp(player2,"Rock")) cout<<"Player1";
            else cout<<"Player2";            
        }
        cout<<endl;
        
    }
}
