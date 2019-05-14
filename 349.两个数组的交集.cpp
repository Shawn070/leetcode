/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集

给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

 */

/*
set: 值唯一
unordered_set: 不唯一

set用法：

begin();            // 返回指向第一个元素的迭代器
end();              // 返回指向最后一个元素的迭代器
clear();            // 清除所有元素
count();            // 返回某个值元素的个数
 
empty();            // 如果集合为空，返回true
 
erase()–删除集合中的元素
 
find()–返回一个指向被查找到元素的迭代器
 
get_allocator()–返回集合的分配器
 
insert()–在集合中插入元素
 
max_size()–返回集合能容纳的元素的最大限值
 
rbegin()–返回指向集合中最后一个元素的反向迭代器
 
rend()–返回指向集合中第一个元素的反向迭代器
 
size()–集合中元素的数目

*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto i : nums2) {
            if (s.count(i)) {
                res.push_back(i);
                s.erase(i);
            }
        }
        return res;
    }
};

