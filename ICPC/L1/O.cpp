#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
int main(){

	int n;
	double a0,an1,c;
	while(scanf("%d",&n)!=EOF){
		double temp=0;
		scanf("%lf%lf",&a0,&an1);
		for(int i=0;i<n;i++){
			scanf("%lf",&c);
			temp+=(n-i)*c;
		}
		double ans=(n*a0+an1-2*temp)/(n+1);
		printf("%.2lf\n",ans);
	}
	
	
	
	return 0;
}