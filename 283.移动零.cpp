/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 * 
 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
 */

// 擦除
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; 
        for (int i=0; i < nums.size(); i++) {
            if (0 != nums[i]) {
                nums[j++] = nums[i];
            }
        }
        
        for (; j < nums.size(); j++)
            nums[j] = 0;
    }
};

// 在原数组上操作，快慢指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n ==1) return n;
        int fast = 1;
        int slow = 0;
        for (; fast < n; fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};

