#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

void  func(double x){
    cout<<x<<" ";
}

int main(){
    deque<double> deq1(3,0.98);

    //元素的加入与删除
    cout<<"-----初始化------"<<endl;
    for_each(deq1.begin(),deq1.end(),func);
    cout<<endl;

    cout<<"-----插入------"<<endl;
    deq1.push_back(9);
    deq1.push_front(1);
    for_each(deq1.begin(),deq1.end(),func);
    cout<<endl;


    cout<<"-----[]修改------"<<endl;
    deq1[2]=9.9;
    for_each(deq1.begin(),deq1.end(),func);
    cout<<endl;


    cout<<"-----迭代器------"<<endl;
    cout<<"begin :"<<*deq1.begin()<<endl;
    cout<<"end   :"<<*(--deq1.end())<<endl;
    cout<<"rbegin:"<<*deq1.rbegin()<<endl;
    cout<<"rend  :"<<*(--deq1.rend())<<endl;
    for_each(deq1.begin(),deq1.end(),func);
    cout<<endl;

    

    return 0;
}
