/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (39.63%)
 * Total Accepted:    20.7K
 * Total Submissions: 52.2K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// 20 ms	8.7 MB
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closeSum = nums[0] + nums[1] + nums[2];
        for(int i=0; i < nums.size() - 2; i++){
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                int threeSum = nums[i] + nums[j] + nums[k];
                if(abs(target - closeSum) > abs(target - threeSum)){
                    closeSum = threeSum;
                } 
                if(threeSum >target) k--;
                else if(threeSum < target) j++;
                else return threeSum;
                            }
        }
        return closeSum;
    }
};


// 16 ms	8.8 MB
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int sum = 0;
        int ins = INT_MAX;
        for (int i = 0; i < len; i++) {
            int l = i + 1;
            int r = len - 1;
            while (l < r) {
                int val = nums[i] + nums[l] + nums[r];
                int n = abs(val - target);
                if (n < ins) {
                    sum = val;
                    ins = n;
                }
                if (val == target) return sum;
                if (val < target) l++;
                if (val > target) r--;
            }
        }
        return sum;
    }
};