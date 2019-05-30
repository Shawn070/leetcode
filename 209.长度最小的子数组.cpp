/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

 */

// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int sum = 0, l = 0, r = 0, n = nums.size(), len = INT_MAX;
//         while (r < n) {
//             sum += nums[r++];
//             while (sum >= s) {
//                 len = min(len, r - l);
//                 sum -= nums[l++];
//             }
//         }
//         return len == INT_MAX ? 0 : len;
//     }
// };

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), len = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++)    //依次将 sum 放入数组 sums
            sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = n; i >= 0 && sums[i] >= s; i--) {  //遍历 >= s 的 sums
            // 找出 sums[i] - s 部分
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
};


