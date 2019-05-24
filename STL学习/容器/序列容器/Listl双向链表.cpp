#include <iostream>
#include <list>
#include<string>
#include <algorithm>

using namespace std;

void out(list<int> p,string gap=" ",string head="List is:"){
    cout<<head<<endl;
    for(auto i:p){
        cout.width(4);
        cout<<i<<gap;}
        cout<<endl;
}


int main(){
    //生成
    list<int> l({1,2,3,5});
    list<int> l2(5,6);
    list<int> l3,l4;
    cout<<"-------初始化-----------"<<endl;
    out(l,",","List 1");
    out(l2,",","List2");
    //复制信息并更新
    l3.assign(l.begin(),l.end());
    out(l3,",","List 3");        
    l3.assign(3,3);
    out(l3,",","List 3");
    l4.merge(l2);//合并了列
    cout<<"-----remove 删除一个5-----"<<endl;
    l4.remove(5);
    out(l4);
    cout<<"-----remove 删除一个5-----"<<endl;
    l4.remove_if([](int a){return a!=5;});
    out(l4);


    //加入删除
    cout<<"-------Push_Back-------"<<endl;
    cout<<"在末尾添加新元素 5"<<endl;
    /*
    类似的还有
    push_front(元素)    插入到头部
    pop_front()        从头部删除
    pop_back()         从尾部删除
    */
    l.push_back(5);
    out(l,",");
    cout<<"-------Insert--------"<<endl;

    l.splice(l.end(),l2);
    l2.splice(l.begin(),l3,l3.begin()++,l3.end()--);

    out(l);
    out(l2);



    //利用迭代器修改
    list<int> ::iterator iter=l.begin();
    //C++11 auto 自动判断类型生成迭代器
    auto p=l.begin();
    *iter=5;
    cout<<"------iter修改----"<<endl;
    out(l);
    *p=7;
    cout<<"-----auto修改-----"<<endl;
    out(l);

    cout<<"-----Erase删除-----"<<endl;
    l.erase(l.begin()++);
    out(l);

    cout<<"-----Inser插入-----"<<endl;

/*
插前
*/    l.insert(l.begin(),5);

    //统一容器不能 swap(l.begin(),l.end());
    swap(l2,l3);

    //cout<<"List 1 number of No.5 is"<<l[2]<<endl;
    cout<<"-----Sort前-----"<<endl;
    out(l);
    cout<<"-----Sort后-----"<<endl;
    l.sort();
    out(l);
    return 0;
}
