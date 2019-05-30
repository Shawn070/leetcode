/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组

给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int sum = 0;
        int l = 0, r = numbers.size() - 1;  //双指针
        while (l < r) {
            sum = numbers[l] + numbers[r];
            if (sum == target) {
                res.push_back(l + 1);
                res.push_back(r + 1);
                break;
            }
            if (sum < target)
                ++l;
            else 
                --r;
        }
        return res;
    }
};

