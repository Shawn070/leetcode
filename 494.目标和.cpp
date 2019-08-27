/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和

给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
注意:

数组的长度不会超过20，并且数组中的值全为正数。
初始的数组的和不会超过1000。
保证返回的最终结果为32位整数。

 */

//DFS:  1676 ms	8.4 MB
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return DFS(nums, 0, 0, S);
    }

    int DFS(vector<int>& nums, int n, int sum, int S) {
        if (n == nums.size()) return (sum == S) ? 1 : 0;
        return DFS(nums, n + 1, sum + nums[n], S) + DFS(nums, n + 1, sum - nums[n], S);
    }
};

//动态规划：	4 ms	8.4 MB
/*
思想：在某个解中正数和为x，负数和的绝对值为y，则x+y=sum，x-y=S，解得x=(sum+S)/2
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum < S || (sum + S) % 2) {
            return false;
        }
        int w = (sum + S) / 2;
        int dp[w + 1] = {0};
        dp[0] = 1;
        for (int num : nums) {
            for (int i = w; i >= num; i--) {
                dp[i] = dp[i] + dp[i - num];
            }
        }
        return dp[w];
    }
};