/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        recursion(nums, res, 0);
        return res;
    }
    
    void recursion(vector<int> nums, vector<vector<int>> &res, int n) {
        if (n == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = n; i < nums.size(); i++) {
            if (n != i && nums[n] == nums[i]) continue; //开始的时候相等则跳过第一个，避免重复
            swap(nums[n], nums[i]);
            recursion(nums, res, n+1);  //递归
        }
    }
};

