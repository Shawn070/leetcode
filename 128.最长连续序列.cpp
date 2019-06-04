/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列

给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxCount = 0, lCount = 0, rCount = 0;
        unordered_map<int, int> count_map;
        for (int i = 0; i < nums.size(); i++) {
            if (!count_map[nums[i]]) {
                lCount = count_map[nums[i] - 1];
                rCount = count_map[nums[i] + 1];
                int sum = lCount + rCount + 1;
                maxCount = max(maxCount, sum);
                // nums[i] - lCount, nums[i], nums[i] + rCount 的 count_map值都应为 sum
                count_map[nums[i]] = count_map[nums[i] - lCount] = count_map[nums[i] + rCount] = sum;
            }
        }
        return maxCount;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> set(nums.begin(), nums.end());
        int res = 1;
        for (auto n : nums) {
            if (!set.count(n)) continue;
            set.erase(n);
            int pre = n - 1, next = n + 1;
            while (set.count(pre)) set.erase(pre--);
            while (set.count(next)) set.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
    }
};

