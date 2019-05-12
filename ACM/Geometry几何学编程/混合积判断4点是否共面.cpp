
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
 
struct Point
{
    int x,y,z;
};
//4点是否共面
bool Point_In_OneArce(Point p[4])
{
        
        Point s1,s2,s3;
        s1.x=p[1].x-p[0].x;
        s1.y=p[1].y-p[0].y;
        s1.z=p[1].z-p[0].z;
        s2.x=p[2].x-p[0].x;
        s2.y=p[2].y-p[0].y;
        s2.z=p[2].z-p[0].z;
        s3.x=p[3].x-p[0].x;
        s3.y=p[3].y-p[0].y;
        s3.z=p[3].z-p[0].z;
        int ans;
        //计算混合积
        /*
        
        
        */
        ans=s1.x*s2.y*s3.z+s1.y*s2.z*s3.x+s1.z*s2.x*s3.y-s1.z*s2.y*s3.x-s1.x*s2.z*s3.y-s1.y*s2.x*s3.z;
        if(ans==0)
            return 1;
        else
            return 0;
}
int main(){

Point p[4];
for(int i=0; i<4; i++)
    scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);

if(Point_In_OneArce(p))
    cout<<"yes";
else
{
    cout<<"NO";
}

}
