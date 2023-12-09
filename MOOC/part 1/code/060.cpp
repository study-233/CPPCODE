/* 060:还是sort简单题 */
#include <bits/stdc++.h>
using namespace std;

struct Point{
	int x;
	int y;
};
struct Rule1{
    bool operator() (const int & a1,const int & a2) const{
        if(a1%10 < a2%10) return true;
        else if(a1%10 == a2%10 && a1>a2) return true;
        else return false;
    }
};
struct Rule2{
    bool operator() (const Point & p1,const Point & p2) const{
        if((p1.x*p1.x+p1.y*p1.y)<(p2.x*p2.x+p2.y*p2.y))
            return true;
        else if((p1.x*p1.x+p1.y*p1.y)==(p2.x*p2.x+p2.y*p2.y))
            if(p1.x<p2.x) return true;
            else if(p1.x==p2.x && p1.y<p2.y) return true;
            else return false;
        else return false;
    }
};

int main(){
    //freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);

	int a[8] = {6,5,55,23,3,9,87,10 };
	sort(a,a+8,Rule1());
	for(int i = 0;i < 8; ++i)
		cout << a[i] << "," ; 
	cout << endl;
	Point ps[8] = {{1,0},{0,1},{0,-1},{-1,0},{1,-1},{1,1},{2,0},{-2,0} } ;
	sort(ps,ps+8,Rule2());
	for(int i = 0;i < 8; ++i)
		cout << "(" << ps[i].x << "," << ps[i].y << ")"; 
	return 0;

}
