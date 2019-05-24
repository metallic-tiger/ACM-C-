#include<iostream>
#include<set>

using namespace std;

void Out(set<int> s){
    for(int i:s)
        cout<<i<<" ";
    cout<<endl;
}

void Out(multiset<int> s){
    for(int i:s)
        cout<<i<<" ";
    cout<<endl;
}
int main() {

	set<int> s1;//建立空的对象
	for (int i : {1, 2, 3, 4, 5, 6, 7, 8, 9})
		s1.insert(i);
	cout << "------set<int>-----" << endl;
	Out(s1);
	cout << "-------------------" << endl << endl;

	multiset<int> s2;//建立空对象
	for (int i : {1, 2, 3, 4, 5, 6, 7, 8, 9})
		s2.insert(i);
	cout << "---multiset<int>---" << endl;
	Out(s2);
	cout << "-------------------" << endl << endl;

	for (int i : {3, 15, 1, 4, 19, 2, 6, 3})
		s1.insert(i);
	cout << "-----set:insert----" << endl;
	Out(s1);
	cout << "重复部分被无视" << endl
		<< "输入时元素自动 [按照大小规则] 被排序" << endl;
	cout << "-------------------" << endl << endl;

	for (int i : {3, 15, 1, 4, 19, 2, 6, 3})
		s2.insert(i);
	cout << "--multiset-insert--" << endl;
	Out(s2);
	cout << "重复部分被保留" << endl
		<< "输入时元素自动 [按照大小规则] 被排序" << endl;
	cout << "-------------------" << endl << endl;

	cout << "-------功能演示------" << endl;
	cout <<"寻找5" <<" "<<*s1.find(5) << endl;
	cout << "计算3的数量"<<s2.count(3) << endl;
	




}
