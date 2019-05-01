/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

 */

// 思路1：暴力法，但是复杂度O(n^2)，显然达不到题目中的要求

// 思路2：动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return NULL;
        int res = INT_MIN;
        int sum = 0;
        for (int num : nums) {
            sum = max(num, sum + num);  // 看前面子序是否为正贡献
            res = max(res, sum);        // 保留每次的最大子序和
        }
        return res;
    }
};

