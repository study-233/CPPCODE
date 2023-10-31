#include <iostream>
using namespace std;
void move(char A, char C,int n){
    cout<<A<<" to "<<C<<endl;
}
void Hanno(char A, char B, char C, int n)
{
	if (n == 1){
		move(A, C, n);
	}
	else{
		//将n-1个圆盘从A柱借助于C柱移动到B柱上
		Hanno(A, C, B, n - 1);
		//将A柱子最后一个圆盘移动到C柱上
		move(A, C, n);
		//将n-1个圆盘从B柱借助于A柱移动到C柱上
		Hanno(B, A, C, n - 1);
	}
}
int main(){
    int n;
    cin>>n;
    Hanno('A','B','C',n);
}
