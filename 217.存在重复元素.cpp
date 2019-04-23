/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 * 
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
 */
/* 思路：
set是一个储存元素的容器，其中每个元素最多只出现一次，元素遵循一个特定
的顺序。元素一旦被放入次容器将不能被修改（修改元素的值），但是可以对元
素进行插入和移除操作。Set内部的元素遵循严格弱排序，因此在寻找元素的时
候比unordered_map稍微慢一些，但是可以直接通过指针操作子分组，set是一
个典型的二分搜索树的应用。

*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};

