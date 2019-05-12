#include<iostream>

using namespace std;

struct Point {
double x,y;
};
 
/*
Pnt[] 为极角排序之后的点集合
为多边形的边数、定点数
*/
Point Bcenter(Point Pnt[],int n){

Point p,s;

double tp,area=0,tpx=0,tpy=0;
p.x=Pnt[0].x;
p.y=Pnt[0].y;

for(int i=1;i<=n;i++){
    s.x=Pnt[(i==n)?0:i].x;
    s.y=Pnt[(i==n)?0:i].y;
    tp=(p.x*s.y-s.x*p.y);
    area+=tp/2;
    tpx+=(p.x+s.x)*tp;
    tpy+=(p.y+s.y)*tp;
    p.x=s.x;
    p.y=s.y;
}

s.x=tpx/(6*area);
s.y=tpy/(6*area);
return s;
}
int main(){

    Point A[4];
    Point center;

    for(int i=0;i<4;i++){
        cin>>A[i].x>>A[i].y;
    }
    center=Bcenter(A,4);
    cout<<"("<<center.x<<","<<center.y<<")"<<endl;
}
