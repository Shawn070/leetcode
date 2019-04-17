/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (35.32%)
 * Total Accepted:    11.6K
 * Total Submissions: 32.8K
 * Testcase Example:  '[1,2,0]'
 *
 * 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,0]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,4,-1,1]
 * 输出: 2
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,8,9,11,12]
 * 输出: 1
 * 
 * 
 * 说明:
 * 
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
 * 
 */

/* 这个思路很好：
遍历一次数组把大于等于1的和小于数组大小的值放到原数组对应位置，
然后再遍历一次数组查当前下标是否和值对应，如果不对应那这个下标
就是答案，否则遍历完都没出现那么答案就是数组长度加1。
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0; i < nums.size(); ++i) {
            int x = nums[i];
            while(x <= nums.size() && x >= 1 && x != nums[x-1]) {
                swap(x, nums[x-1]);
            }
        }
        for (int j=0; j < nums.size(); ++j) {
            if (j + 1 != nums[j])
                return j+1;
        }
        return nums.size() + 1;
    }
};

