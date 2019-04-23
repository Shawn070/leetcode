/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// 思路：The trick is: A^B^A=B

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        int first = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            first = first ^ nums[i];
        }
        return first;
    }
};

