#include<iostream>

using namespace std;

const double eps=1e-10;

struct Point{
int x,y;
};

double min (double a,double b)
{
    return a<b?a:b;
}

double max (double a,double b)
{
    return a>b?a:b;
}
/*
判断两个由两个点组成的矩形
是否存在 重叠
*/
bool Rectangle(/*第一个矩型的两点*/ Point a, Point b, /*第二个矩型的两点*/ Point c, Point d)
{
    return ((min(a.x, b.x) > max(c.x, d.x)) || (min(a.y, b.y) > max(c.y, d.y)) || (min(c.x, d.x) > max(a.x, b.x)) || (min(c.y, d.y) > max(a.y, b.y))) ? 0: 1;
}

bool inter(/*第一个矩型的两点*/ Point a, Point b, /*第二个矩型的两点*/ Point c, Point d){
    //如果矩形不重合必定不相交
    if(!Rectangle(a,b,c,d))
    return 0;

    /*
    跨立实验：
    一个线段的两端在另一个线段的两侧

    h*j 跨立实验1

    i*k 跨立实验2
    */
    double h,i,j,k;
    h=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    i=(b.x-a.x)*(d.y-a.y)-(b.y-a.y)*(d.x-a.x);
    
    j=(d.x-c.x)*(a.y-c.y)-(d.y-c.y)*(a.x-c.x);
    k=(d.x-c.x)*(b.y-c.y)-(d.y-c.y)*(b.x-a.x);
    return h*j<=eps&&j*k<=eps;
}

int main(){
    Point a,b,c,d;
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cin>>c.x>>c.y;
    cin>>d.x>>d.y;

    if(inter(a,b,c,d))
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    return 0;
}
