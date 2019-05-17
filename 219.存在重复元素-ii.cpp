/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II

给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false

 */

/*
用map存放值到索引的哈希表，然后一一查找map中是否有相同的值，若有则判断索引差
是否小于等于k，不是则修改map中的索引值。
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        unordered_map<int, int> um;
 
        for (int i=0; i < nums.size(); i++) {
            if (um.count(nums[i])) {
                if (i - um[nums[i]] < k)
                    return true;
                else
                    um[nums[i]] = i;
            } else {
                um.insert(unordered_map<int, int>::value_type(nums[i], i));
            }
        }
    }
};

