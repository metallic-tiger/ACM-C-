#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

//重新定义有序对叫 Complex
typedef pair<string,int> Complex;

void Print(map<string,int,greater<string >> &m){
    cout<<"------Print-----"<<endl;
    map<string ,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        Complex p=*it;//顺手测试
        cout<<p.first<<" "<<it->second<<endl;
    }
    cout<<"----------------"<<endl;
}
void Print(multimap<string,int,greater<string >> &m){
    cout<<"------Print-----"<<endl;
    map<string ,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        Complex p=*it;//顺手测试
        cout<<p.first<<" "<<it->second<<endl;
    }
    cout<<"----------------"<<endl;
}

int main(){

    /*
    默认排序为 less<>

    */
   map<string,int,greater<string >> m1;
   multimap<string,int,greater<string >> m2;


    m1.insert(Complex("first",1));
    m1.insert(Complex("second",2));
    m1.insert(Complex("third",3));
    m1.insert(Complex("first",2));//测试第一元素重复
    m1.insert(Complex("one",1));//测试第二元素重读
    cout<<"------Map-------"<<endl;
    Print(m1);

    m2.insert(Complex("first",1));
    m2.insert(Complex("second",2));
    m2.insert(Complex("third",3));
    m2.insert(Complex("first",2));//测试第一元素重复
    m2.insert(Complex("one",1));//测试第二元素重读
    cout<<"---multimap-----"<<endl;
    Print(m2);

    /*
    新增与查询方法
    */
    cout<<"Map \"first\" is : "<<m1["first"]<<endl;
    cout<<"MultiMap \"first\" is : "<<m1["first"]<<endl;
    m1["tree"]=4;
    cout<<"MultiMap  New \"tree\" is : "<<m1["tree"]<<endl;
   Print(m1);

    /*
    erase 会删除所有的 键值相同的内容
    */
   m2.erase("first");
   Print(m2);
   return 0;
}
