/* 9. 蛇形填数 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
    int n;
    cin>>n;
    int a[n][n];
    int row = 0;
    int col = n-1;
    int left=0,up=0;
    int right=n-1,down=n-1;
    for(int i=1;i<=n*n;i++){
        a[row][col]=i;

        if(col==right){
            if(row==down) {col--;}
            else row++;
        }
        else if(col==left){
            if(row==up) {col++;}
            else row--;
        }        
        else if(row==up){
            if(col==right) {row++;}
            else col++;
        }
        else if(row==down){
            if(col==left) {row--;}
            else col--;
        }

    }



    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

