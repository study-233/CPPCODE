#include <bits/stdc++.h>
using namespace std;
class Point{    //基类Point类的声明
    public:    //公有函数成员
        void InitP(float xx=0, float yy=0) {X=xx;Y=yy;}
        void Move(float xOff, float yOff) {X+=xOff;Y+=yOff;}
        float GetX() {return X;}
        float GetY() {return Y;}
    private:    //私有数据成员
        float X,Y;
};
class Rectangle:public Point{
    public:
        Point p;
    private:
        float l;
        float w;
        float Getl(){return l;}
        float Getw(){return w;}
}
int main(){
    float x,y,l,w;
    cin>>x>>y>>l>>w;
    Rectangle R1;
    R1.InitP
}