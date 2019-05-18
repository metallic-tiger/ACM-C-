#include <iostream>
#include <algorithm>

#include<vector>

using namespace std;

void out(vector<int> v){
    for(int i:v)
    cout<<i<<" ";
    cout<<endl;
}

int main(){
vector<int> ve({1,3,5,9,8,1,2,3,5,4});

// for_each()
// 对序列中的每个元素执行某操作。
cout<<"-------for_each-前-------"<<endl;
out(ve);
for_each(ve.begin(),ve.end(),[](int &i){i=i+1;});
cout<<"-------for_each-后-------"<<endl;
out(ve);
cout<<"-------for_each-end-------"<<endl;
cout<<endl;
cout<<endl;
// 查找
// find()
// 在序列中找出某个值的第一次出现的位置。

cout<<"-------find-前-------"<<endl;
out(ve);
cout<<find(ve.begin(),ve.end(),5)-ve.begin()<<endl;
cout<<"-------find-end-------"<<endl;
cout<<endl;
cout<<endl;

// find_if()
// 在序列中找出符合某谓词的第一个元素。
cout<<"-------find_if-前-------"<<endl;
out(ve);
cout<<find_if(ve.begin(),ve.end(),[](int i){return i>6;})-ve.begin()<<endl;
cout<<"-------find_if-end-------"<<endl;
cout<<endl;
cout<<endl;

// find_end()
// 在序列中找出一子序列的最后一次出现的位置。
cout<<"-------find_end-前-------"<<endl;
out(ve);
cout<<find_end(ve.begin(),ve.end(),vector<int>({2,3,4}))-ve.begin()<<endl;
cout<<"-------find-end-后-------"<<endl;
cout<<endl;
cout<<endl;

// search()
// 在序列中找出一子序列的第一次出现的位置。

// search_n()
// 在范围内查找相等值的序列






// find_first_of()

// 在序列中找出第一次出现指定值集中之值的位置。

// adjacent_find()

// 在序列中找出相邻的一对值。

// 计数

// count()

// 在序列中统计某个值出现的次数。

// count_if()

// 在序列中统计与某谓词匹配的次数。

// 比较

// mismatch()

// equal()

// 找出两个序列相异的第一个元素。

// 比较两个序列是否相等。

// 修改性序列操作（27个）

// 类型

// 函数名

// 说明

// 复制

// copy()

// 从序列的第一个元素起进行复制。

// copy_backward()

// 从序列的最后一个元素起进行复制。

// 交换

// swap()

// 交换两个元素。

// swap_ranges()

// 交换指定范围的元素。

// iter_swap()

// 交换由迭代器所指的两个元素。

// 变换

// transform()

// 将某操作应用于指定范围的每个元素。

// 替换

// replace()

// 用一个给定值替换一些值。

// replace_if()

// 替换满足谓词的一些元素。

// replace_copy()

// 复制序列时用一给定值替换元素。

// replace_copy_if()

// 复制序列时替换满足谓词的元素。

// 填充

// fill()

// 用一给定值取代所有元素。

// fill_n()

// 用一给定值取代前n个元素。

// 生成

// generate()

// 用一操作的结果取代所有元素。

// generate_n()

// 用一操作的结果取代前n个元素。

// 删除

// remove()

// 删除具有给定值的元素。

// remove_if()

// 删除满足谓词的元素。

// remove_copy()

// 复制序列时删除具有给定值的元素。

// remove_copy_if()

// 复制序列时删除满足谓词的元素。

// 唯一

// unique()

// 删除相邻的重复元素。

// unique_copy()

// 复制序列时删除相邻的重复元素。

// 反转

// reverse()

// 反转元素的次序。

// reverse_copy()

// 复制序列时反转元素的次序。

// 环移

// rotate()

// 循环移动元素。

// rotate_copy()

// 复制序列时循环移动元素。

// 随机

// random_shuffle()

// 采用均匀分布来随机移动元素。

// 划分

// partition()

// 将满足某谓词的元素都放到前面。
// stable_partition()

// 将满足某谓词的元素都放到前面并维持原顺序。

// 序列排序及相关操作（27个）

// 类型

// 函数名

// 说明

// 排序

// sort()

// 以很好的平均效率排序。

// stable_sort()

// 排序，并维持相同元素的原有顺序。

// partial_sort()

// 将序列的前一部分排好序。

// partial_sort_copy()

// 复制的同时将序列的前一部分排好序。

// 第n个元素

// nth_element()

// 将第n各元素放到它的正确位置。

// 二分检索

// lower_bound()

// 找到大于等于某值的第一次出现。

// upper_bound()

// 找到大于某值的第一次出现。

// equal_range()

// 找到（在不破坏顺序的前提下）可插入给定值的最大范围。

// binary_search()

// 在有序序列中确定给定元素是否存在。

// 归并

// merge()

// 归并两个有序序列。

// inplace_merge()

// 归并两个接续的有序序列。

// 有序结构

// 上的

// 集合操作

// includes()

// 一序列为另一序列的子序列时为真。

// set_union()

// 构造两个集合的有序并集。

// set_intersection()

// 构造两个集合的有序交集。

// set_difference()

// 构造两个集合的有序差集。

// set_symmetric_difference()

// 构造两个集合的有序对称差集（并-交）。

// 堆操作

// push_heap()

// 向堆中加入元素。

// pop_heap()

// 从堆中弹出元素。

// make_heap()

// 从序列构造堆。

// sort_heap()

// 给堆排序。

// 最大

// 和最小

// min()

// 两个值中较小的。

// max()

// 两个值中较大的。

// min_element()

// 序列中的最小元素。

// max_element()

// 序列中的最大元素。

// 词典比较

// lexicographical_compare()

// 两个序列按字典序的第一个在前。

// 排列

// 生成器

// next_permutation()

// 按字典序的下一个排列。

// prev_permutation()

// 按字典序的前一个排列。

return 0;
}
