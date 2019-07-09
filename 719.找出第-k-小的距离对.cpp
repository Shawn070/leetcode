/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 
给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。

示例 1:

输入：
nums = [1,3,1]
k = 1
输出：0 
解释：
所有数对如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
提示:

2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.

 */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int l = 0, r = nums[len - 1] - nums[0];
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            int j = 0;
            for (int i = 1; i < len; i++) {
                while (nums[i] - nums[j] > mid) j++;
                cnt += i - j;
            }
            if (cnt < k) 
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

