#include<iostream>
#include<string>

using namespace std;

int main(){

//循环新写法
for(auto a : {1,2,3,4,5,6,7,8,9})
    cout<<a<<endl;

//取消字符串的转义
string  A=R"(hello world////////A/'')";


cout<<A<<endl;
}
