/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 * 
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        create(nums, res, 0);
        return res;
    }

    void create(vector<int>& nums, vector<vector<int>> &res, int n) {
        if (n == nums.size() - 1) {
            res.push_back(nums);
        } else {
            for (int i=n; i < nums.size(); i++) {
                swap(nums[i], nums[n]);
                create(nums, res, n+1);
                swap(nums[i], nums[n]);
            }
        }
    }
    
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};

