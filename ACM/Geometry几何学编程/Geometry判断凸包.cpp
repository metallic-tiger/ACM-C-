#include <iostream>
/*
排序写错了
目前效率为O(N^2)
*/
#define MAXSize 50

using namespace std;

struct Point
{
    float x, y;
};

struct PointSet
{
    Point P[MAXSize];
    int lenth;
};

/*
进行矩阵运算
计算两点的 相对于基础点的向量内积
利用矩阵运算可知
|A.x-Base.x |A.y-Base.y|=內积（带正负的面积）
|B.x-Base.x |B.y-Base.y|
=(A.x-Base.x)*(B.y-Base.y)-(B.x-Base.x)*(A.y-Base.y)

根据面积的正负大小确定A点相对于B点是否在基础点的前方（顺时针参考）

同时这个也是根据极坐标排序的偏序关系原则
计算面积的公式
float mult(Point Base,Point A,Point B){
    return (A.x-Base.x)*(B.y-Base.y)-(B.x-Base.x)*(A.y-Base.y);
}
*/
int mult(Point Base, Point A, Point B)
{
    return (A.x - Base.x) * (B.y - Base.y) - (B.x - Base.x) * (A.y - Base.y);
}

PointSet GetTop(PointSet All)
{
    PointSet WALL;
    Point o;
    WALL.lenth = 0;
    //排除特殊情况 没有点，单点 ，双点，三点（一平面）
    if (All.lenth == 0 || All.lenth == 1 || All.lenth == 2 || All.lenth == 3)
    {
        int i = 0;
        while (i != All.lenth)
        {
            WALL.P[i].x = All.P[i].x;
            WALL.P[i].y = All.P[i].y;
            i++;
        }
        WALL.lenth = All.lenth;
        return WALL;
    }

    //找到处于最靠近x轴负无穷的点并删除这个点
    int Max = 0;
    int Min = 0;
    for (int i = 0; i < All.lenth; i++)
    {
        if (All.P[i].x < All.P[Min].x)
            Min = i;
        if (All.P[i].x == All.P[Min].x&&All.P[i].y < All.P[Min].y)
            Min = i;
    }
    WALL.P[0] = All.P[Min];
    WALL.lenth += 1;

    for (int i = Min; i < All.lenth - 1; i++)
    {
        All.P[i] = All.P[i + 1];
    }
    All.lenth--;

    /*
    失败了
进行相对于 基准点进行极角排序
此处使用了快速排序加快的速度
*/
    // for (int i = 0; i < All.lenth / 2; i++)
    // {
    //     for (int j = i; j < All.lenth - i; j++)
    //     {
    //         if (mult(WALL.P[0], All.P[i], All.P[Max]) > 0)
    //             Max = i;
    //         if (mult(WALL.P[0], All.P[i], All.P[Max]) == 0 && All.P[i].y > All.P[Max].y)
    //             Max = i;
    //         if (mult(WALL.P[0], All.P[Min], All.P[i])<0)
    //             Min = i;
    //         if (mult(WALL.P[0], All.P[Min], All.P[i])==0&& All.P[i].y < All.P[Min].y)
    //             Min = i;
    //     }
    //     o = All.P[i];
    //     All.P[i] = All.P[Max];
    //     All.P[Max] = o;
    //     o = All.P[All.lenth - 1 - i];
    //     All.P[All.lenth - 1 - i] = All.P[Min];
    //     All.P[Min] = o;

    //     Max = Min = All.lenth / 2;
    // }

    for (int i = 0; i < All.lenth; i++)
    {Max=i;
        for(int j= i+1; j < All.lenth; j++){
            if (mult(WALL.P[0], All.P[Max], All.P[j]) > 0)
               Max = j;
            if (mult(WALL.P[0], All.P[Max], All.P[j]) == 0 && All.P[i].y < All.P[Max].y)
               Max = j;
        }
        o = All.P[i];
        All.P[i] = All.P[Max];
        All.P[Max] = o;
    }

    cout << "start" << endl;
    for (int i = 0; i < All.lenth; i++)
        cout << All.P[i].x << " " << All.P[i].y << endl;
    cout << "end" << endl;

    /*
开始进行连线啦
参考了
https://blog.csdn.net/zhouzi2018/article/details/82178412
的方法
*/
    WALL.P[1] = All.P[0];
    WALL.lenth++;
    for (int i = 1; i < All.lenth; i++)
    {
        cout << "||" << All.P[i].x << " " << All.P[i].y << endl
             << "||" << All.P[i + 1].x << " " << All.P[i + 1].y << "||" << endl
             << WALL.lenth << endl;

        if (mult(WALL.P[WALL.lenth - 1], WALL.P[0], All.P[i])<0)
            continue;

        if (mult(WALL.P[WALL.lenth - 1], WALL.P[WALL.lenth - 2], All.P[i])>=0)
        {
            WALL.P[WALL.lenth] = All.P[i];
            WALL.lenth++;
        }
        else
        {
            WALL.P[WALL.lenth - 1] = All.P[i];
        }
    }
    return WALL;
}

int main()
{
    PointSet All, Wall;
    int i;

    All.lenth = Wall.lenth = 0;

    cout << "输入点的个数" << endl;
    cin >> i;
    All.lenth = i;
    while (i)
    {
        i--;
        cin >> All.P[i].x >> All.P[i].y;
        cout << All.P[i].x << " " << All.P[i].y << endl;
    }
    Wall = GetTop(All);
    for (int i = 0; i < Wall.lenth; i++)
        cout << Wall.P[i].x << " " << Wall.P[i].y << endl;

    return 0;
}
