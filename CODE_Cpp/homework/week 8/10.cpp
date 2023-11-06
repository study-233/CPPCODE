#include <iostream>
#include <stdio.h>
using namespace std;
int a[100000];
int shuzi[100000];
int p1=0;
int cycle(int x){
    int newx1=0,newx2=0;
    int p=0,n,m,temp=0;
    int i,j;
    while(x){
        a[p]=x%10;
        x/=10;
        p++;
    }
    n=p+1;
	m = n;            //因为每进行一次第一轮循环，需要排序的数据都要“--”，因此定义变量m=n；
	for ( i = 0; i < n; i++) {
		int exchange = 0;           //记录这一轮会不会有数据的交换；
		for ( j = 0; j < m-1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				exchange = 1;
			}
		}
		m--;
		if (!exchange)  //若没有数据的交换，则数据已经排列完毕，跳出循环；
			break;
	}
    for(int i1=1; i1 < n; i1++){
        newx1=newx1*10+a[n-i1];
    }
    for(int j1=1; j1 < n; j1++){
        newx2=newx2*10+a[j1];
    }
    shuzi[p1]=newx1-newx2;
    cout<<shuzi[p1]<<" ";
    for(int p2=p1-1;p2>=0;p2--){
        if(shuzi[p1]==shuzi[p2])
            return 0;
    }
    p1++;
    return cycle(shuzi[p1-1]);
}
int main(){
    int x;
    cin>>x;
    cout<<x<<" ";
    cycle(x);
}