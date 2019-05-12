#include<iostream>

using namespace std;

typedef long long ll;
typedef struct  //  点结构
{
    ll x, y;
} Point;

//  判断线段是否和圆相交
int segOnCircle(Point &L1, Point &L2,Point &O,ll &r)
{
    ll a, b, c, dist_1, dist_2, angle_1, angle_2;   //  ax + by + c = 0;
    if (L1.x == L2.x)                           //  当x相等
    {
        a = 1, b = 0, c = -L1.x;
    }
    else if (L1.y == L2.y)                      //  当y相等
    {
        a = 0, b = 1, c = -L1.y;
    }
    else//两点式变化
    {
        a = L1.y - L2.y;
        b = L2.x - L1.x;
        c = L1.x * L2.y - L1.y * L2.x;
    }
    dist_1 = a * O.x + b * O.y + c;
    dist_1 *= dist_1;
    dist_2 = (a * a + b * b) * r * r;
    if (dist_1 > dist_2)
    {
        return 0;
    }
    angle_1 = (O.x - L1.x) * (L2.x - L1.x) + (O.y - L1.y) * (L2.y - L1.y);
    angle_2 = (O.x - L2.x) * (L1.x - L2.x) + (O.y - L2.y) * (L1.y - L2.y);
    if (angle_1 > 0 && angle_2 > 0)
    {
        return 1;
    }
    return 0;
}
int main(){
    Point L1,L2,O;
    ll r=2;

    L1.x=0,L1.y=0;
    L2.x=3,L2.y=0;
    O.x=2,O.y=2;

    r=1;
    
    cout<<segOnCircle(L1,L2,O,r);

    return 0;
}
