#include<iostream>
#include<vector> //模板头文件

#include<algorithm>

using namespace std;

int  main(){

vector<int> intV;//实例化
vector<int >intV2;
intV2.push_back(5);
/*
调整容器的大小

默认的数值非常大，为了使用效率建议手动调整数值大小避免不必要的内存占用

*/
intV.reserve(3);

intV.clear();//清除所有的内容
intV.push_back(1);//在末尾添加内容
intV.push_back(2);
/*
insert 方法

第一个是迭代器
可以进行++，--操作 不能直接进行+-的操作。
*/
intV.insert(intV.begin(),-1);
intV.pop_back();//删除末尾的一个元素
intV.erase(intV.begin());//删除迭代器指示的元素

/*
算法
for_each(起始位置，结束位置，操作) 遍历
*/
intV.push_back(2);
intV.push_back(1);
intV.push_back(8);
intV.push_back(5);

//swap(intV2.begin(),intV.end());//失败

cout<<"------for each---------"<<endl;
for_each(intV.begin(),intV.end(),[](int i){cout<<i<<endl;});

cout<<"-------sort------------"<<endl;
sort(intV.begin(),intV.end());

for_each(intV.begin(),intV.end(),[](int i){cout<<i<<endl;});
cout<<"--------end------------"<<endl;
cout<<intV[0]<<endl;//取元素的方法
cout<<intV.size()<<endl;//查询大小
cout<<intV.capacity()<<endl;//查询容量
cout<<intV.max_size()<<endl;//查询最大容量

if(intV.empty())//是否为空
cout<<"Yes"<<endl;
else
cout<<"NO"<<endl;

/*
at 方法遍历数组

需要配合循环
*/
int num=intV.size();
for(int i=0;i<num;i++)
cout<<"It's "<<intV.at(i)<<endl;



return 0;
}
