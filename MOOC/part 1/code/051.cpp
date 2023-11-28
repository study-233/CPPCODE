/* 051:指针练习：MyMax */
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void * MyMax(void * p,int size,int n,int (*compare)(void*,void*)){		//void类型可以被转换为其他任何类型
	char* pi = (char*) p ;		//  强制类型转换为char*	char占一字节
    int j=0,max=0;
    int i=0;
    for(;i<n;i++){
        if(max<compare(pi+size*i,pi)){		//调用比较函数
            max=compare(pi+size*i,pi);		//找出差值最大的数
            j=i;							//用 pi+size*i 表示指针位置
        }
    }
    return (pi+size*j) ;
}
int Compare1(void * n1,void * n2)
{
	int * p1 = (int * )n1;
	int * p2 = (int * )n2;
	return ((*p1)%10) - ((*p2)%10);
}
int Compare2(void * n1,void * n2)
{
	int * p1 = (int * )n1;
	int * p2 = (int * )n2;
	return *p1 - *p2;
}
#define eps 1e-6
int	Compare3(void * n1,void * n2)
{
	float * p1 = (float * )n1;
	float * p2 = (float * )n2;
	if( * p1 - * p2 > eps)
		return 1;
	else if(* p2 - * p1 > eps)
		return -1;
	else
		return 0; 
}
int main(){
    freopen("E:\\CPPCODE\\MOOC\\code\\in.txt","r",stdin);
	int t;
	int a[10];
	float d[10];
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0;i < n; ++i)
			cin >> a[i];
		for(int i = 0;i < n; ++i)
			cin >> d[i];
		int * p = (int *) MyMax(a,sizeof(int),n,Compare1);
		cout << * p << endl;
		p = (int *) MyMax(a,sizeof(int),n,Compare2);
		cout << * p << endl;
		float * pd = (float * )MyMax(d,sizeof(float),n,Compare3);
		cout << * pd << endl;
	}
	return 0;
}

