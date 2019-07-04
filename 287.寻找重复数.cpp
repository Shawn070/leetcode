/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数

给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]
输出: 2
示例 2:

输入: [3,1,3,4,2]
输出: 3
说明：

不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。

 */

// 方法一：二分法（16 ms	10 MB）
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1;
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            int cnt = 0;
            for (int num : nums)
                if (num <= mid)
                    cnt++;
            if (cnt <= mid)
                l = mid + 1;
            else 
                r = mid;
        }
        return r;
    }
};


// 方法二：快慢指针（16 ms	9.7 MB）
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, finder = 0;
        while (1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            
            if (slow == fast)
                break;
        }
        
        while (1) {
            slow = nums[slow];
            finder = nums[finder];
            
            if (slow == finder)
                return finder;
        }
    }
};
